public class Solution {
	public boolean isMatch(String s, String p) {
		// compiler, checks if the regular expression is valid
		// status: 0. begin or after '*', 1. any char except '*'
		int status = 0;
		int i = 0;
		boolean error = false;
		while (!error && i < p.length()) {
			char c = p.charAt(i);
			switch (status) {
			case 0:
				if (c == '*') {
					error = true;
				} else {
					status = 1;
				}
				break;
			case 1:
				status = (c == '*') ? 0 : 1;
				break;
			default:
				error = true;
			}
			i++;
		}
		if  (error) {
			return false;
		}
		
		return match(s, p);
	}

	// can also be accepted by submitting this function only
	private boolean match(String s, String p) {
		// when p is empty
		if (p.length() <= 0) {
			return s.equals(p);
		}
		
		// when p is not empty
		char c = p.charAt(0);
		// see if the second char is '*'
		char n = (p.length() >= 2) ? p.charAt(1) : 0;
		if (n == '*') {
			// match multiple chars
			// index i for s, j for p
		    int i = 0, j = 2;
			// let 'c*' match empty string
			if (match(s, p.substring(j, p.length()))) {
				return true;
			}
			// let 'c*' match at least 1 char
			while (i < s.length() && isEqual(s.charAt(i), c)) {
				if (match(s.substring(i + 1, s.length()), p.substring(j, p.length()))) {
					return true;
				}
				i++;
			}
		} else {
			// match single char
			if (s.length() <= 0) {
				return false;
			}
			if (c != '.' && c != s.charAt(0)) {
				return false;
			}
			return match(s.substring(1, s.length()), p.substring(1, p.length()));
		}
		return false;
	}
	
	private boolean isEqual(char s, char p) {
	    return (p == '.') ? true : (p == s);
	}
}