#include "Automaton.h"

std::set<State*> Automaton::epsilonClosure (const std::set<State*>& states) const {
    std::stack<State*> stack;
    for (State* st: states) {
        stack.push(st);
    }

    std::set<State*> result = states;
    while (!stack.empty()) {
        State* p = stack.top();
        stack.pop();

        for (State* u: p->getTransitionsBySymbol(EMPTY_TRANSITION)) {
            if (result.find(u) == result.end()) {
                result.insert(u);
            }
        }
    }

    return result;
}

std::set<State*> Automaton::move (const std::set<State*>& states, const Symbol& symbol) const {
    std::set<State*> result;
    for (State* st: states) {
        std::vector<State*> aux = st->getTransitionsBySymbol(symbol);
        for (State* destinationState: aux) {
            result.insert(destinationState);
        }
    }
    return result;
}

State* Automaton::getStateByIdentifier (const std::string& identifier) const {
    for (State* st: _states) {
        if (st->getIdentifier() == identifier) {
            return st;
        }
    }
    return nullptr;
}

Automaton Automaton::toDFA () const {
    std::stack<std::set<State*>> stack;
    std::set<std::set<State*>> DFAstates;

    std::map<std::set<State*>, std::map<Symbol, std::set<State*>>> transitions;

    std::set<State*> q0 = epsilonClosure({ _initial_state });

    stack.push(q0);
    DFAstates.insert(q0);
    while (!stack.empty()) {
        std::set<State*> T = stack.top();
        stack.pop();

        for (const Symbol& symbol: _alphabet.getSymbols()) {
            std::set<State*> H = epsilonClosure(move(T, symbol));
            if (DFAstates.find(H) == DFAstates.end()) {
                stack.push(H);
                DFAstates.insert(H);
            }
            transitions[T][symbol] = H;
        }
    }

    std::map<std::set<State*>, std::string> identifiers;
    char currentIdentifier = 'A';

    Automaton dfa;

    for (std::set<State*> currentStates: DFAstates) {
        dfa.createState(std::string(1,currentIdentifier), anyAccepted(currentStates));
        currentIdentifier++;
    }

    for (std::set<State*> currentStates: DFAstates) {
        State* st = dfa.getStateByIdentifier(identifiers[currentStates]);
        for (auto p: transitions.at(currentStates)) {
            // p.first es el simbolo de la transicion
            // p.second es el conjunto al que va
            st->addTransition(p.first, dfa.getStateByIdentifier(identifiers[p.second]));
        }
    }

    dfa.setInitialState(dfa.getStateByIdentifier(identifiers[q0]));

    return dfa;
}

bool Automaton::anyAccepted (const std::set<State*>& states) const {
    for (State* st: states) {
        if (st->isAccepted()) {
            return true;
        }
    }
    return false;
}