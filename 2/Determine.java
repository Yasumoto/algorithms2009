/*
 * Determine.java
 * Joe Smith
 * Algorithms - Spring 2009
 * Erik Linstead
 * Chapman University
 * Released under GPLv2 or later.
 */

/*
 * Parser
 * 	Deal with braces ({})
 * 	EPS
 * 	Multiple states in a brace
 * Walk through the NFA to the DFA
 * Print out DFA
 */

/*
 * The awkwardly simple main class
 */

public class Determine{
	public static void main(String[] args)
	{
                FiniteStateAutomata FSA = new FiniteStateAutomata();

		Parser parse = new Parser(args[0], FSA);

		Builder build = new Builder(FSA);
	}
}
