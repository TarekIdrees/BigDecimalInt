# BigDecimalInt
Different variations of types int and float exist in **C++** and other languages. They are usually limited by **minimum** and **maximum** values. Sometimes it is desired to have versions of these types with unlimited bounds. Java solves this problem by providing **BigInteger and **BigDecimal** classes. In this problem it is required to develop a new **C++** type (class) that can hold **unlimited decimal** integer values and performs arithmetic operations on them. The program  develop in **C++** , BigDecimalInt that supports writing statements with extremely long integer values like these:

* BigDecimalInt num1("123456789012345678901234567890");
* BigDecimalInt num2("113456789011345678901134567890");
* BigDecimalInt num3 = num2 + num1;
* cout << "num1 = " << num1 << endl;
* cout << "num2 = " << num2 << endl;
* //236913578023691357802369135780
* cout << "num2 + num1 = " << num3 << endl;

# The BigDecimalInt class contain different functions :
* BigDecimalInt (string decStr)
* BigDecimalInt (int decInt)
* BigDecimalInt operator + (BigDecimalInt anotherDec)
* BigDecimalint operator - (BigDecimalint anotherDec)
* BigDecimalInt operator = (BigDecimalInt anotherDec)
* BigDecimalint addDiffrentSign (BigDecimalint &decStr2)
* BigDecimalint SubSameSign (BigDecimalint &decStr2)
* BigDecimalint SubDiffrentSign (BigDecimalint &decStr2)
* BigDecimalint addSameSign (BigDecimalint  &decStr2)
* Int size()
* friend ostream& operator << (ostream& out, BigDecimalInt b)

# Calculation Testing :
1. **Perform Addition**
2. **Perform Subtraction**
3. **Exit**

<body> 
>> 1  &nbsp;&nbsp;&nbsp;&nbsp; // Addition <br>
>> 123456789012345678901234567890 <br>
Num1 = 123456789012345678901234567890 <br>
>> = 113456789011345678901134567890 <br>
Num2 = 113456789011345678901134567890 <br>
Num1 + Num2 = 236913578023691357802369135780 <br>
<br><br>
>> 2  &nbsp;&nbsp;// Substraction <br>
>> 1230000000000000001 <br>
Num1 = 1230000000000000001 <br>
>> 30000000000000001 <br>
Num2 = 30000000000000001 <br>
Num1 - Num2 = 1200000000000000000 <br>
<br><br>
>> 1  &nbsp;&nbsp;// Addition<br>
>> - 1230000000000000001 <br>
Num1 = - 1230000000000000001 <br>
>> 30000000000000001 <br>
Num2 = 30000000000000001 <br>
Num1 + Num2 = - 1200000000000000000 <br>
<br><br>
>> 3 //Exit 



</body>


