#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//state structure
struct State {
	unordered_set<int> states;
	unordered_set<char> transitions;
};

int main() {
	//initial dfa transition
	vector<State> dfa(3); //we have 3 states in dfa
	dfa[0].states = { 0 };
	dfa[0].transitions.insert('a');
	dfa[0].states = { 1 };

	dfa[1].states = { 1 };
	dfa[1].transitions.insert('b');
	dfa[1].states = { 2 };

	dfa[2].states = { 2 };
	dfa[2].transitions.insert('c');
	dfa[2].states = { 0 };

	//converting dfa to nfa transition
	vector<State> nfa(3); //we have 3 states in nfa

	nfa[0].states = { 0 };
	nfa[0].transitions.insert('a');
	nfa[0].states = { 1 };
	
	nfa[1].states = { 1 };
	nfa[1].transitions.insert('b');
	nfa[1].states = {}; //there is no transiton from q1 on 'b'

	nfa[2].states = { 2 };
	nfa[2].transitions.insert('a');
	nfa[2].states = {0}; //transition back to q0 from q2 on 'a'

	//displaying nfa 
	for (int i = 0; i < nfa.size(); ++i) {
		cout << "State q" << i << ":" << endl;
		cout << "transitions:" << endl;
		for (char c : nfa[i].transitions) {
			cout << "on '" << c << "' to state:";
			for (int state : nfa[i].states) {
				cout << "q" << state << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}