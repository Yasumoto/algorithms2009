/*
 * FiniteStateAutomata.java
 * Joe Smith
 * Algorithms - Spring 2009
 * Erik Linstead
 * Chapman University
 * Released under GPLv2 or later.
 */

public class FiniteStateAutomata{
	public FiniteStateAutomata()
	{
	}
}

class Transition 
{
	String Target;
	String Input;
	String Home;

	public void setTarget(String Target)
	{
		this.Target = Target;
	}

	public String getTarget()
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
