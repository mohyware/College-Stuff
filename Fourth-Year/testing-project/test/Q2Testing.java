import org.testng.annotations.DataProvider;
import org.testng.annotations.Test;
import static org.testng.Assert.*;

import qursaan.Sailing;

/**
 * Q2: White-Box/SC testing
 * 
 * EP tests cover most nodes, but missing:
 * - Node 9: else if (windforce == 11) condition - needs weekend||july=true,
 * windforce==11
 * - Node 10: result = true (line 24) - the fault line
 * 
 * To achieve 100% statement coverage, we need:
 * - A test with (weekend||july)=true, windforce==11 to cover the else if branch
 */
public class Q2Testing {

    @DataProvider(name = "scData")
    public static Object[][] scData() {
        return new Object[][] {
                { "TC9", true, false, 11, false }, // weekend=true, windforce=11 (covers line 23-24, expects false but
                                                   // code returns true)
                { "TC10", false, true, 11, false } // july=true, windforce=11 (covers line 23-24, expects false but code
                                                  // returns true)
        };
    }

    @Test(dataProvider = "scData", groups = "SC")
    public void testSC(String id, boolean weekend, boolean july, int wind, Object expected) throws Exception {
        if ("Exception".equals(expected)) {
            try {
                Sailing.available(weekend, july, wind);
                fail("Expected Exception for " + id);
            } catch (Exception e) {
                // Exception expected
                assertTrue(e.getMessage().contains("Invalid parameter"));
            }
        } else {
            assertEquals(Sailing.available(weekend, july, wind), expected,
                    "Test case " + id + " failed");
        }
    }
}
