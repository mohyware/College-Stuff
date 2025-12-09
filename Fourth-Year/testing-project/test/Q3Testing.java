import org.testng.annotations.DataProvider;
import org.testng.annotations.Test;
import static org.testng.Assert.*;

import qursaan.Sailing;

/**
 * Q3: Black-Box/Combinational testing (using truth-tables)
 * 
 * Analysis:
 * Causes (inputs):
 * C1: weekend (boolean: true, false)
 * C2: july (boolean: true, false)
 * C3: windforce (int: 0<=windforce<=4 for valid wind)
 * 
 * Effects (outputs):
 * E1: available() returns true
 * E2: available() returns false
 * 
 * 
 * Full Truth Table (8 candidate rules):
 * Rule | weekend | july | windforce (0-4) | Effect
 * -----|---------|------|-----------------|-------
 * 1 | T | T | 0-4 | E1 (true)
 * 2 | T | F | 0-4 | E1 (true)
 * 3 | F | T | 0-4 | E1 (true)
 * 4 | F | F | 0-4 | E2 (false)
 * 5 | T | T | 5-12 | E2 (false) 
 * 6 | T | F | 5-12 | E2 (false) 
 * 7 | F | T | 5-12 | E2 (false) 
 * 8 | F | F | 5-12 | E2 (false) 
 * 
 *  * 1 -> Full Truth Table (8 candidate rules):
 * Rule | weekend | july | windforce (0-4) | Effect
 * -----|---------|------|-----------------|-------
 * 1 | T | - | 0-4 | E1 (true) <- 1,2
 * 2 | T | - | 0-4 | E1 (true) <- 1,2
 * 3 | F | T | 0-4 | E1 (true)
 * 4 | F | F | 0-4 | E2 (false) 
 * 5 | T | - | 5-12 | E2 (false)  <- 5,6
 * 6 | T | - | 5-12 | E2 (false)  <- 5,6
 * 7 | F | - | 5-12 | E2 (false)  <- 7,8
 * 8 | F | - | 5-12 | E2 (false)  <- 7,8
 * 
 *  * 2 -> Full Truth Table (8 candidate rules):
 * Rule | weekend | july | windforce (0-4) | Effect
 * -----|---------|------|-----------------|-------
 * 1 | T | - | 0-4 | E1 (true)
 * 2 | F | T | 0-4 | E1 (true)
 * 3 | F | F | 0-4 | E2 (false)
 * 4 | T | - | 5-12 | E2 (false) <- 4,5
 * 5 | F | - | 5-12 | E2 (false) <- 4,5
 * 
 *  * 3 -> Final Truth Table (4 candidate rules):
 * Rule | weekend | july | windforce (0-4) | Effect
 * -----|---------|------|-----------------|-------
 * 1 | T | - | 0-4 | E1 (true)
 * 2 | F | T | 0-4 | E1 (true)
 * 3 | F | F | 0-4 | E2 (false)
 * 4 | - | - | 5-12 | E2 (false) 
 */
public class Q3Testing {

    @DataProvider(name = "combinationalData")
    public static Object[][] combinationalData() {
        return new Object[][] {
                // Rule 1: weekend=T, july=*, windforce=0-4 → true
                { "CT1", true, false, 2, true },

                // Rule 2: weekend=F, july=T, windforce=0-4 → true
                { "CT2", false, true, 3, true },

                // Rule 3: weekend=F, july=F, windforce=0-4 → false
                { "CT3", false, false, 1, false },

                // Rule 4: weekend=*, july=*, windforce=5-12 → false
                { "CT4", true, true, 6, false }
        };
    }

    @Test(dataProvider = "combinationalData", groups = "Combinational")
    public void testCombinational(String id, boolean weekend, boolean july, int wind, boolean expected)
            throws Exception {
        assertEquals(Sailing.available(weekend, july, wind), expected,
                "Combinational test case " + id + " failed");
    }
}
