/*
 * Builder.java
 * Joe Smith
 * Algorithms - Spring 2009
 * Erik Linstead
 * Chapman University
 * Released under GPLv2 or later.
 */

import java.util.*;
import java.lang.Number;

public class Builder 
{
	public Builder(FiniteStateAutomata FSA)
	{
		//Find new initial state
		// (the epsilon closure)
		FSA.newStartState = createEpsilon(FSA, FSA.startState);

		System.out.println("========");
		System.out.println(FSA.newStartState);

		FSA.builtStates = buildStates(FSA, FSA.newStartState);

		System.out.println("&&&&&&&&&&&&");
		System.out.println(FSA.builtStates);
	}

	private ArrayList<String> createEpsilon(FiniteStateAutomata FSA, ArrayList<String> state)
	{
		ArrayList<String> createdState = new ArrayList<String>();

		createdState.addAll(state);

		for (int j = 0; j < state.size(); ++j)
		{
			for (int i = 0; i < FSA.transitions.size(); ++i)
			{            
				if (Integer.parseInt(FSA.transitions.get(i).Home) == Integer.parseInt(state.get(j)))
				{                            
					if (FSA.transitions.get(i).Input == "EPS")
						createdState.addAll(FSA.transitions.get(i).Target);
				}
			}
		}

		return createdState;
	}

	private ArrayList<ArrayList<String>> buildStates(FiniteStateAutomata FSA, ArrayList<String> state)
	{
		ArrayList<ArrayList <String> > builtStates = new ArrayList<ArrayList<String>>();

		for (int i = 0; i < state.size(); ++i)
		{
			//System.out.println("States: " + state.get(i) + "\n");
			for (int j = 0; j < FSA.Alphabet.length; ++j)
			{
				//System.out.println("Alphabet: " + FSA.Alphabet[j] + "\n");
				for (int k = 0; k < FSA.transitions.size(); ++k)
				{
					//System.out.println(k);
					//System.out.println(state.get(i));
					//System.out.println(FSA.transitions.get(k).Home);
					//System.out.println("transitions: " + FSA.transitions.get(k).Home + "\n");
					if (state.get(i).equals(FSA.transitions.get(k).Home))
					{
                                                        //System.out.println(FSA.Alphabet[j]);
							//System.out.println(FSA.transitions.get(k).Input);
						if (FSA.Alphabet[j].equals(FSA.transitions.get(k).Input))
						{
							builtStates.add(createEpsilon(FSA, FSA.transitions.get(k).Target));
						}
					}
				}
			}
		}

			//System.out.println(state.get(i));
		return builtStates;
	}
}
