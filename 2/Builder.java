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
	}

	private ArrayList<String> createEpsilon(FiniteStateAutomata FSA, String state)
	{
		ArrayList<String> createdState = new ArrayList<String>();

		createdState.add(state);

		for (int i = 0; i < FSA.transitions.size(); ++i)
		{            
			if (Integer.parseInt(FSA.transitions.get(i).Home) == Integer.parseInt(state))
			{                            
				if (FSA.transitions.get(i).Input == "EPS")
					createdState.addAll(FSA.transitions.get(i).Target);
			}
		}

		return createdState;
	}
}
