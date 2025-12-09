import java.util.Random;
import org.testng.annotations.Test;
import static org.testng.Assert.*;

import qursaan.Sailing;

/**
 * Q4: Black-Box/Random testing
 * 
 * Decision Tree Analysis:
 * Expected output = random(t, f)
 * 
 * If output is true:
 * - weekend = random(t, f)
 * - If weekend is true, then july = random(t, f)
 * - Otherwise (weekend is false), july must be t (true)
 * - windforce = random(0..4)
 * 
 * Otherwise (output is false):
 * - Option 1: weekend = false, july = false, windforce = random(0..12) [any
 * value]
 * - Option 2: (weekend OR july) = true, windforce = random(5..12)
 */
public class Q4Testing {

    @Test(groups = "random")
    public void testRandom() throws Exception {
        Random outRand = new Random();
        Random wkRand = new Random();
        Random juRand = new Random();
        Random wfRand = new Random();

        for (int i = 0; i < 1000000; i++) {
            boolean expected = outRand.nextBoolean();
            boolean weekend, july;
            int windforce;

            if (expected) {
                // Output should be true: (weekend OR july should be true) AND (windforce < 5)
                weekend = wkRand.nextBoolean();
                if (weekend) {
                    july = juRand.nextBoolean();
                } else {
                    july = true;
                }
                windforce = wfRand.nextInt(5);
            } else {
                // Output should be false: (weekend AND july should be false) OR (windforce > 5)
                boolean swing = wkRand.nextBoolean();
                if (swing) {
                    weekend = wkRand.nextBoolean();
                    july = wkRand.nextBoolean();
                    windforce = wfRand.nextInt(5, 12);
                } else {
                    weekend = false;
                    july = false;
                    windforce = wfRand.nextInt(0, 12);
                }
            }

            assertEquals(Sailing.available(weekend, july, windforce), expected,
                    "Random test failed at iteration " + i +
                            " with weekend=" + weekend + ", july=" + july + ", windforce=" + windforce);
        }
    }
}