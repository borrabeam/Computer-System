#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/** = number of times c occurs in s.
Example: numberc('a', "aaabbbaccabda") == 6
*/
int numberc(char c, char* s) {
    if (s[0] == '\0')
        return 0;

    if (s[0] == c){

        return 1 + numberc(c, s + 1);

    }
    else{
        return numberc(c, s + 1 );
    }

	

}

 /** = number of chars in s that are not c. 
Example: numberNotc('a', "aaabbbaccabda") == 7)
 */
int numberNotc(char c, char* s) {

	if (s[0] == '\0')
        return 0;

    if (s[0] != c){

        return 1 + numberNotc(c, s + 1);

    }

    else{
        return numberNotc(c, s + 1 );
    }

}

/** = a copy of s but with all occurrences of c replaced by d.
Example: replace("abeabe", 'e', '$') = "ab$ab$".
*/
char* replace(char* s, char c, char d) {
    if (s[0] == '\0')
        return " ";
    char* save;
    save = (char*)malloc(sizeof(char));

    if (s[0] == c){
        *save = d;
        return strcat(save, replace(s+1, c, d));
    }
    else{
        *save = s[0];
        return strcat(save, replace(s+1, c, d));
    }


}


 /** = a copy of s with adjacent duplicates removed.
 Example: for s = "abbcccdeaaa", the answer is "abcdea".*/
char* rem1(char* s) {
    if (*s == '\0') 
        return " ";
    char *save;
    save = (char*) malloc(sizeof(char));


    if (s[0] == s[1]) return strcat(save, rem1(s+1));

    else {
        *save = *s;
        return strcat(save, rem1(s+1));
}
}



/** = number of the digits in the decimal representation of n.
e.g. numDigits(0) = 1, numDigits(3) = 1, numDigits(34) = 2.
numDigits(1356) = 4.
Precondition: n >= 0. */
int numDigits(int n) {
    if (n < 1)
        return 0;

    return numDigits(n/10) + 1;

    

}

/** = sum of the digits in the decimal representation of n.
e.g. sumDigits(0) = 0, sumDigits(3) = 3, sumDigits(34) = 7,
sumDigits(345) = 12.
Precondition: n >= 0. */
int sumDigits(int n) {
    if (n < 1)
        return 0;


	return sumDigits(n/10) + n%10 ;

}

/** = a copy of s with to_remove_char removed.
Example: removeChar("abeabe", 'e') = "abab". */

char* removeChar(char* s, char to_remove_char) {
    if (s[0] == '\0')
        return "";
    char* save;
    save = (char*)malloc(sizeof(char));

    if (s[0] == to_remove_char){
        // *save = "";
        return strcat(save, removeChar(s+1,to_remove_char));
    }
    else{
        *save = s[0];
        return strcat(save, removeChar(s+1,to_remove_char));
    }


}

/** = a copy of s with characters in reverse order.
Example: reverse("abcdefg") = "gfedcba". */
char* reverse(char* s) {
    if (s[0] == '\0')
        return "";
    
    reverse(s+1);
    printf("%c",*s);
    
    
        
}



int numOnes(int n){
    if (n == 0) {
        return 0;
    }
    else{
        return (n % 2 + numOnes(n / 2));
    }

}
int main() {
	char s1[] = "aaabbbaccabda";

	// put all your testcases here
    
    printf("%d\n" ,numberc('a', s1));
    printf("%d\n" ,numberc('b', s1));
    printf("%d\n" ,numberc('c', s1));

    printf("%d\n", numberNotc('a', s1));
    printf("%d\n", numberNotc('b', s1));
    printf("%d\n", numberNotc('c', s1));

    printf("%s" ,replace(s1,'a','$'));
    printf("%s" ,replace(s1,'b','$'));
    printf("%s" ,replace(s1,'c','$'));

    printf("%s",rem1("asdsadwqe"));
    printf("%s",rem1("zvzzrtvb"));
    printf("%s",rem1("qqqwert"));
    
    printf("%d",numDigits(1455));
    printf("%d",numDigits(374));
    printf("%d",numDigits(77));

    printf("%d",sumDigits(1455));
    printf("%d",sumDigits(374));
    printf("%d",sumDigits(77));


    printf("%s",removeChar("abcdea",'a'));
    printf("%s",removeChar("qwertwwqqr",'w'));
    printf("%s",removeChar("sasdfgsssj",'s'));

    printf("%s",reverse("abcdefg"));
    printf("%s",reverse("lickda"));
    printf("%s",reverse("borrabeam"));

    printf("%d",numOnes(7));
    printf("%d",numOnes(9));
    printf("%d",numOnes(2));

	return 0;
}