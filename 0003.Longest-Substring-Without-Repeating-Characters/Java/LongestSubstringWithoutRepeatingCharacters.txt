public class Solution {
    public int lengthOfLongestSubstring(String s) {
		int maxL = 0;
		int lastRepeatIndex = -1;
		int[] lastPosition = new int[256];
		for (int i = 0; i < 256; ++i) {
			lastPosition[i] = -1;
		}
		for (int i = 0; i < s.length(); ++i) {
			char c = s.charAt(i);
			if (lastPosition[c] >= 0) {
				if (i - lastRepeatIndex - 1 > maxL) {
					maxL = i - lastRepeatIndex - 1;
				}
				lastRepeatIndex = lastPosition[c];
				for (int j = 0; j < 256; j++) {
					if (lastPosition[j] < lastRepeatIndex && lastPosition[j] >= 0) {
						lastPosition[j] = -1;
					}
				}
				lastPosition[c] = i;
			} else {
				lastPosition[c] = i;
			}
		}
		if (s.length() - 1 - lastRepeatIndex > maxL) {
			maxL = s.length() - 1 - lastRepeatIndex;
		}
		return maxL;
    }
}