package com.mathsolver;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;


class SolverTest
{
    @Test
    public void SolveTest()
    {
        assertEquals(5,Solver.Solve("2+3"));
        assertEquals(5,Solver.Solve("1*5"));
        assertEquals(120,Solver.Solve("123-3"));
        assertEquals(50,Solver.Solve("200/4"));
        assertEquals(4.8,Solver.Solve("2.4*2"));
        assertEquals(9,Solver.Solve("3^2"));
        assertEquals(3,Solver.Solve("(1+2)"));
        assertEquals(2,Solver.Solve("((1.2)+2.8)*2/4"));
        assertEquals(24,Solver.Solve("(2+2)*(3+3)"));
    }
}