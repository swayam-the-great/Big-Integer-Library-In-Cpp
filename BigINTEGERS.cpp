#include<iostream> 
using namespace std  ;

class BigInt {
//-------------------------------------------------------------------------------------------------------------------------------------------------------
public :
string sumOfBigInt(const string & s1 , const string &s2)
{

    int l1 = s1.length();
    int l2 = s2.length();

    // cout<<" size of a1 " << l1 << endl ;
    // cout<<" size of a2 " << l2 << endl ;
    
    int* a1 = new int[l1] ;
    int* a2 = new int[l2] ;

    // coverting strings into arrays 
    for (int x = 0; x < l1; x++) {
        a1[x] = s1[x] - '0'; // Subtracting '0' to convert char to int
    }

    for (int y = 0; y < l2; y++) {
        a2[y] = s2[y] - '0'; // Subtracting '0' to convert char to int
    }
     
    //  // printing arrays
    //      cout<<" array a1 " << endl ;
    //  for (int i = 0; i < l1; i++) {
    //     cout << a1[i] << " ";
    // }
    //     cout << endl ;
    //      cout<<"  array a2 "  << endl ;
    //  for (int j = 0; j < l2; j++) {
    //     cout << a2[j] << " ";
    // }



// Sum of Two Array Starts Here :

    int i = l1 - 1;
    int j = l2 - 1;
    int carry = 0;
    int resultSize = (l1 >= l2 ? l1 : l2) + 1; // Max size needed for the result

    
    int* ans = new int[resultSize]();
     
      
    int k = resultSize - 1;

    while (i >= 0 || j >= 0 || carry) {
        int val1 = (i >= 0) ? a1[i] : 0;
        int val2 = (j >= 0) ? a2[j] : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        ans[k] = sum % 10;

        i--;
        j--;
        k--;
    }
//    cout << " Your Sum of bIG iNT  "  << endl ;
    //    //printing ans
    //  for (int e = 0; e < resultSize; e++) {
    //     cout << ans[e] << " ";
    // }


  string result;

    for (int x = 0; x < resultSize; ++x) {
        // Ensure the digit is between 0 and 9
        if (ans[x] < 0 || ans[x] > 9) {
            throw invalid_argument("Array elements must be single digits (0-9).");
        }
        // Convert each digit to its character representation
        result += (ans[x] + '0');  // Convert integer to character
    }

   
    

   delete []a1;
   delete []a2;
    delete []ans ;

     return result;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------


string DifferenceOfBigInt(const string& s1, const string& s2) {
    int l1 = s1.length();
    int l2 = s2.length();

    int* a1 = new int[l1];
    int* a2 = new int[l2];

    // Converting strings into arrays
    for (int x = 0; x < l1; x++) {
        a1[x] = s1[x] - '0'; // Subtracting '0' to convert char to int
    }

    for (int y = 0; y < l2; y++) {
        a2[y] = s2[y] - '0'; // Subtracting '0' to convert char to int
    }

    // Ensure a1 is the larger number
    if (l1 < l2 || (l1 == l2 && s1 < s2)) {
        cout << "Error: s1 must be greater than or equal to s2 for subtraction." << endl;
        return ""; // Indicate error
    }

    // Prepare the answer array
    int* ans = new int[l1];
    int borrow = 0;
    int i = l1 - 1;
    int j = l2 - 1;
    int k = l1 - 1;

    while (i >= 0 || j >= 0) {
        int valueA1 = (i >= 0) ? a1[i] : 0; // Get value from a1 or 0 if out of bounds
        int valueA2 = (j >= 0) ? a2[j] : 0; // Get value from a2 or 0 if out of bounds

        int diff = valueA1 - valueA2 - borrow; // Calculate the difference

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        ans[k] = diff; // Store the result
        i--;
        j--;
        k--;
    }

    // Handle leading zeros and create the result string
    string result;
    bool leadingZero = true;

    for (int x = 0; x < l1; x++) {
        if (ans[x] != 0 || !leadingZero) {
            result += (ans[x] + '0');  // Convert integer to character
            leadingZero = false; // Stop ignoring leading zeros
        }
    }

    // If result is empty, it means the result is 0
    if (result.empty()) {
        result = "0";
    }

    delete[] ans;
    delete[] a1;
    delete[] a2;

    return result;
}



//-------------------------------------------------------------------------------------------------------------------------------------------------------


// void productOfBigInt(string &s1 , string &s2)
//  {

// }


string productOfBigInt(string s1 ,string s2)
{
   
    int n = s1.length();
    int m = s2.length();

    // cout<<" size of num1 " << n << endl ;
    // cout<<" size of num2 " << m << endl ;
    
    int* num1 = new int[n] ;
    int* num2 = new int[m] ;

    // coverting strings into arrays 
    for (int x = 0; x < n; x++) {
        num1[x] = s1[x] - '0'; // Subtracting '0' to convert char to int
    }

    for (int y = 0; y < m ; y++) {
        num2[y] = s2[y] - '0'; // Subtracting '0' to convert char to int
    }

    int result[n + m];

// Initialize result array with zeros
    for (int i = 0; i < n + m; ++i) {
        result[i] = 0;
    }

    // Multiply each digit of num1 by each digit of num2
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = num1[i] * num2[j];
            int sum = mul + result[i + j + 1]; // current position in result

            result[i + j + 1] = sum % 10;      // store the unit place
            result[i + j] += sum / 10;         // carry the tens place
        }
    }

    // Remove leading zeros and find the starting index
    int startIndex = 0;
    while (startIndex < n + m - 1 && result[startIndex] == 0) {
        startIndex++;
    }


 string ans;

    for (int x = startIndex; x <  n + m ; ++x) {
        // Ensure the digit is between 0 and 9
        if (result[x] < 0 || result[x] > 9) {
            throw invalid_argument("Array elements must be single digits (0-9).");
        }
        // Convert each digit to its character representation
        ans += (result[x] + '0');  // Convert integer to character
    }

    // // Print the result
    // for (int i = startIndex; i < n + m; ++i) {
    //     cout << result[i];
    // }
    // cout << endl;

     
     return ans;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

//fuction to convert string to int 

int stringToInt(const string &str) {
    int result = 0; // Resulting integer
    bool isNegative = false; // Flag for negative numbers
    int startIdx = 0; // Starting index for conversion

    // Check for negative sign
    if (str[0] == '-') {
        isNegative = true;
        startIdx = 1; // Start conversion from the next character
    }

    // Process each character in the string
    for (int i = startIdx; i < str.size(); ++i) {
        // Check if the character is a digit
        if (str[i] < '0' || str[i] > '9') {
            throw invalid_argument("Invalid input: Non-numeric character found");
        }

        // Convert character to integer and update result
        result = result * 10 + (str[i] - '0');
    }

    // Apply the negative sign if necessary
    if (isNegative) {
        result = -result;
    }

    return result;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------


// Function to perform division of large numbers represented as strings
string longDivision( string &number, string &str ) {


    // ACTUAL DIVISION STARTS HERE 

 int divisor = stringToInt(str) ;

    

    string result; // Store the result of the division
    int idx = 0;   // Initialize index
    int temp = 0;  // Temporary variable for holding the current number

    // Loop through each digit of the number
    while (idx < number.size()) {
        // Update temp to include the next digit
        temp = temp * 10 + (number[idx] - '0');

        // If temp is greater than or equal to the divisor
        if (temp >= divisor) {
            // Append the quotient to the result
            result += (temp / divisor) + '0';
            // Update temp to be the remainder
            temp = temp % divisor;
        } else if (!result.empty()) {
            // If result is not empty, append 0 for leading digits
            result += '0';
        }

        idx++; // Move to the next digit
    }

    // Handle case where result is empty (divisor is larger than the number)
    if (result.empty()) {
        return "0";
    }
     
   
    return result;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Function to manually reverse a string
string reverseString(const string &str) {
    string reversed;
    for (int i = str.size() - 1; i >= 0; --i) {
        reversed += str[i];
    }
    return reversed;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------

// Function to calculate power of a large number
string power(const string &base, int exp) {

    
    string result = "1"; // Initialize result to 1

    for (int i = 0; i < exp; ++i) {
        result = productOfBigInt(result, base); // Multiply result by base
    }

    return result;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------


// karatsuba 
string addLargeIntegers(const string &s1, const string &s2) {
    int l1 = s1.length();
    int l2 = s2.length();

    int* a1 = new int[l1];
    int* a2 = new int[l2];

    // Converting strings into arrays 
    for (int x = 0; x < l1; x++) {
        a1[x] = s1[x] - '0'; // Convert char to int
    }

    for (int y = 0; y < l2; y++) {
        a2[y] = s2[y] - '0'; // Convert char to int
    }

    int i = l1 - 1;
    int j = l2 - 1;
    int carry = 0;
    int resultSize = max(l1, l2) + 1;

    int* ans = new int[resultSize]();
    int k = resultSize - 1;

    while (i >= 0 || j >= 0 || carry) {
        int val1 = (i >= 0) ? a1[i] : 0;
        int val2 = (j >= 0) ? a2[j] : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        ans[k] = sum % 10;

        i--;
        j--;
        k--;
    }

    string result;
    for (int x = 0; x < resultSize; ++x) {
        result += (ans[x] + '0');  // Convert integer to character
    }

    delete[] a1;
    delete[] a2;
    delete[] ans;

    // Remove leading zeros
    while (result.length() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    return result;
}

// Function to subtract two large integers represented as strings
string subtractLargeIntegers(const string& s1, const string& s2) {
    int l1 = s1.length();
    int l2 = s2.length();

    int* a1 = new int[l1];
    int* a2 = new int[l2];

    for (int x = 0; x < l1; x++) {
        a1[x] = s1[x] - '0'; // Convert char to int
    }

    for (int y = 0; y < l2; y++) {
        a2[y] = s2[y] - '0'; // Convert char to int
    }

    // Ensure a1 is the larger number
    if (l1 < l2 || (l1 == l2 && s1 < s2)) {
        cout << "Error: s1 must be greater than or equal to s2 for subtraction." << endl;
        return ""; // Indicate error
    }

    int* ans = new int[l1];
    int borrow = 0;
    int i = l1 - 1;
    int j = l2 - 1;
    int k = l1 - 1;

    while (i >= 0 || j >= 0) {
        int valueA1 = (i >= 0) ? a1[i] : 0;
        int valueA2 = (j >= 0) ? a2[j] : 0;

        int diff = valueA1 - valueA2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        ans[k] = diff;
        i--;
        j--;
        k--;
    }

    string result;
    bool leadingZero = true;

    for (int x = 0; x < l1; x++) {
        if (ans[x] != 0 || !leadingZero) {
            result += (ans[x] + '0');  // Convert integer to character
            leadingZero = false;
        }
    }

    if (result.empty()) {
        result = "0";
    }

    delete[] ans;
    delete[] a1;
    delete[] a2;

    return result;
}



//-------------------------------------------------------------------------------------------------------------------------------------------------------


// Function implementing the Karatsuba multiplication algorithm
string karatsuba(const string& x, const string& y) {
    if (x == "0" || y == "0") return "0";
    if (x.size() == 1 && y.size() == 1) {
        return to_string((x[0] - '0') * (y[0] - '0'));
    }

    int n = max(x.size(), y.size());
    int half = (n + 1) / 2;

    string x_high = x.size() > half ? x.substr(0, x.size() - half) : "0";
    string x_low = x.substr(x.size() - half);
    string y_high = y.size() > half ? y.substr(0, y.size() - half) : "0";
    string y_low = y.substr(y.size() - half);

    string z0 = karatsuba(x_low, y_low);
    string z1 = karatsuba(addLargeIntegers(x_low, x_high), addLargeIntegers(y_low, y_high));
    string z2 = karatsuba(x_high, y_high);

    string middle = subtractLargeIntegers(z1, addLargeIntegers(z2, z0));

    string result = z2 + string(2 * half, '0');
    result = addLargeIntegers(result, middle + string(half, '0'));
    result = addLargeIntegers(result, z0);

    return result;
}




};



int main()
{
    string s1 , s2 , ans ;
  s1  = "55121315233";
  s2 = "114421555";

    BigInt b ;

    


    cout << endl ;

    // cout << " Your diFFerence of bIG iNT  "  << endl ;
    ans = b.karatsuba(s1,s2);
    cout << " ans is "<< ans << endl ;

}