#include <iostream>

using namespace std;

void splitStr(string &line, string &x, string &y) {
    // Init pointer at the beginning of the string
    char *p = &line[0];

	// Check comma
	int commaCount = 0;

    // Iterate through every characters in the string
	while ((*p) != '\0') {
		if ((*p) == ',') commaCount++;
		p++;
	}
	if (commaCount != 1) {
		x += 'a';
		y += 'a';
		return;
	}

    // Reset pointer to the beginning of the string
	p =  &line[0];

	// Split data into string x and y
	while ((*p) != ',') {
		x += *p;
		p++;
	}
	p++;
	while ((*p) != '\0' && (*p) != '\r') {
		y += *p;
		p++;
	}	
	return;
}

bool numberChk(string &inp) { 
    // Init pointer at the beginning of the string
    char *p = &inp[0];

    int dotcount = 0;
    
    // Check positive/negative characters
    if ((*p) == '+' || (*p) == '-') p++;
    
    // Iterate through all characters in the string
    while ((*p) != '\0') {
        // Check dot
        if ((*p) == '.'){ 
            dotcount++;
            if (dotcount > 1) return false;
        } 
        // Check each characters is a number or not
		else if ((*p) < '0' || (*p) > '9' ) {
			return false;
		}
        // Pointer increment
        p++;
    }
    return true;
}