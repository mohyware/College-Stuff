import org.testng.annotations.DataProvider;
import org.testng.annotations.Test;
import static org.testng.Assert.*;

import qursaan.Sailing;

/**
 * Q1: Black-Box/Equivalence Partitioning (EP) testing
 * 
 * Equivalence Partitioning Analysis:
 * The method Sailing.available(weekend, july, windforce) has three input parameters:
 * 
 * 1. weekend (boolean):
 *    - Partition EP1: true (weekend)
 *    - Partition EP2: false (not weekend)
 * 
 * 2. july (boolean):
 *    - Partition EP3: true (in July)
 *    - Partition EP4: false (not in July)
 * 
 * 3. windforce (int):
 *    - Partition EP5: windforce < 0 (invalid - should throw Exception)
 *    - Partition EP6: 0 <= windforce <= 4 (valid, low wind - favorable for sailing)
 *    - Partition EP7: 5 <= windforce <= 12 (valid, high wind - unfavorable for sailing)
 *    - Partition EP8: windforce > 12 (invalid - should throw Exception)
 * 
 * Test Cases Coverage:
 * - TC1: EP1 (weekend=true), EP4 (july=false), EP6 (windforce=2) → Expected: true
 * - TC2: EP1 (weekend=true), EP3 (july=true), EP6 (windforce=2) → Expected: true
 * - TC3: EP1 (weekend=true), EP4 (july=false), EP7 (windforce=6) → Expected: false
 * - TC4: EP2 (weekend=false), EP3 (july=true), EP7 (windforce=6) → Expected: false
 * - TC5: EP2 (weekend=false), EP4 (july=false), EP6 (windforce=2) → Expected: false
 * - TC6: EP2 (weekend=false), EP4 (july=false), EP7 (windforce=6) → Expected: false
 * - TC7: EP1 (weekend=true), EP3 (july=true), EP5 (windforce=-1) → Expected: Exception
 * - TC8: EP2 (weekend=false), EP4 (july=false), EP8 (windforce=13) → Expected: Exception
 * 
 * These test cases cover all equivalence partitions for valid boundary testing
 * and exception handling for invalid inputs.
 */
public class Q1Testing {
    @DataProvider(name = "epData")
    public static Object[][] epData() {
        return new Object[][] {
                { "TC1", true, false, 2, true },
                { "TC2", false, true, 2, true },
                { "TC3", true, false, 6, false },
                { "TC4", false, true, 6, false },
                { "TC5", false, false, 2, false },
                { "TC6", false, false, 6, false },
                { "TC7", true, true, -1, "Exception" },
                { "TC8", false, false, 13, "Exception" }
        };
    }

    @Test(dataProvider = "epData", groups = "EP")
    public void testEP(String id, boolean weekend, boolean july, int wind, Object expected) throws Exception {
        if ("Exception".equals(expected)) {
            try {
                Sailing.available(weekend, july, wind);
                fail("Expected Exception for " + id);
            } catch (Exception e) {
                assertEquals(e.getMessage(), "Invalid parameter: windForce");
            }
        } else {
            assertEquals(Sailing.available(weekend, july, wind), expected);
        }
    }
}
