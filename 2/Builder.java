/*
 * Builder.java
 * Joe Smith
 * Algorithms - Spring 2009
 * Erik Linstead
 * Chapman University
 * Released under GPLv2 or later.
 */

import java.util.*;

public class Builder 
{
	public Builder(FiniteStateAutomata FSA)
	{
		//Find new initial state
		// (the epsilon closure)
		FSA.newStartState = createEpsilon(FSA, FSA.startState);

		System.out.println("========");
		System.out.println(FSA.startState);
	}

	private ArrayList<String> createEpsilon(FiniteStateAutomata FSA, String state)
	{
		ArrayList<String> createdState = new ArrayList<String>();

		for (int i = 0; i < FSA.transitions.size(); ++i)
		{
			if (FSA.transitions.get(i).Home == state)
			{
				createdState.addAll(FSA.transitions.get(i).Target);
			}
		}

		return createdState;
	}
}
