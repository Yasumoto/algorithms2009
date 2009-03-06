/*
 * FiniteStateAutomata.java
 * Joe Smith
 * Algorithms - Spring 2009
 * Erik Linstead
 * Chapman University
 * Released under GPLv2 or later.
 */

import java.util.*;

public class FiniteStateAutomata{
	//First
	// The list of states that are possible in the NFA
	public String[] states;

	// The second line of the file
	public String[] Alphabet;
	// 3rd
	public ArrayList<String> startState = new ArrayList<String>();
	// 4th
	public String acceptState;

	//5th to the end
	public ArrayList<Transition> transitions = new ArrayList<Transition>();


	// The new stuff to be created:
	public ArrayList<String> newStartState = new ArrayList<String>();

	public ArrayList<ArrayList<String>> builtStates = new ArrayList<ArrayList<String>>();

	public FiniteStateAutomata()
	{
	}
}

class Transition 
{
	public ArrayList<String> Target = new ArrayList<String>();
	String Input;
	// May need to be an arraylist?
	String Home;

	public void setTarget(ArrayList<String> Target)
	{
		this.Target = Target;
	}

	public ArrayList<String> getTarget()
	{
		return this.Target;
	}

	public void setInput(String Input)
	{
		this.Input = Input;
	}

	public String getInput()
	{
		return this.Input;
	}

	public void setHome(String Home)
	{
		this.Home = Home;
	}

	public String getHome()
	{
		return this.Home;
	}
}
