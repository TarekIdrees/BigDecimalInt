#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class BigDecimalint
{
    string decStr;
    int decInt;
    bool sign;
    vector<int> v1;
    vector<int>::iterator it;
    vector<int>::iterator it2;

public:
    BigDecimalint() {}
    BigDecimalint(int decInt)
    {
        if(decInt<0)
        {
            sign=true;
            decInt*=-1;
        }
        else
            sign=false;
        int temp=decInt;
        while(temp>0)
        {

            int remend=temp%10;
            v1.push_back(remend);
            temp/=10;
        }

    }

    BigDecimalint(string decStr)
    {
        if(decStr[0]=='-')
            sign=true;
        else
            sign=false;
        for(int i=0; i<decStr.size(); i++)
        {

            if(decStr[i]>='0' && decStr[i]<='9')
            {
                v1.push_back(decStr[i]-'0');
            }
            else
                continue;
        }
        reverse(v1.begin(),v1.end());
    }

    BigDecimalint operator +(BigDecimalint anotherDec)
    {
        if(this->sign==anotherDec.sign)
        {
            BigDecimalint newob;
            newob=this->addSameSign(anotherDec);
            return newob;
        }
        else
        {
            BigDecimalint newob;
            newob=this->addDiffrentSign(anotherDec);
            return newob;

        }
    }
    BigDecimalint operator -(BigDecimalint anotherDec)
    {
        if(this->sign==anotherDec.sign)
        {
            BigDecimalint newob;
            newob=this->SubSameSign(anotherDec);
            return newob;
        }
        else
        {
            BigDecimalint newob;
            newob=this->SubDiffrentSign(anotherDec);
            return newob;

        }

    }
    BigDecimalint operator =(BigDecimalint anotherDec)
    {
        this->sign=anotherDec.sign;
        this->v1=anotherDec.v1;
        return *this;
    }
    BigDecimalint addDiffrentSign(BigDecimalint &decStr2)
    {
        BigDecimalint diffrentSignObject;

        if(this->sizee()==decStr2.sizee())
        {
            it=v1.end()-1;
            it2=decStr2.v1.end()-1;
            bool ifEqual=true;

            if(sizee()==decStr2.sizee())
            {
                if(*it>*it2)
                {
                    diffrentSignObject.sign=this->sign;
                    ifEqual=false;
                }
                else if(*it<*it2)
                {
                    diffrentSignObject.sign=decStr2.sign;
                    ifEqual=false;
                }
                else if(*it==*it2)
                {
                    it2=decStr2.v1.end()-2;
                    for(it=v1.end()-2; it<=v1.begin(); it--)
                    {

                        if(*it>*it2)
                        {
                            diffrentSignObject.sign=this->sign;
                            ifEqual=false;
                            break;
                        }
                        else if(*it<*it2)
                        {
                            diffrentSignObject.sign=decStr2.sign;
                            ifEqual=false;
                            break;
                        }

                        it2--;
                    }
                }
                if(ifEqual)
                {
                    diffrentSignObject.v1.push_back(0);
                    diffrentSignObject.sign=false;
                    return diffrentSignObject;
                }
                else
                {
                    if(diffrentSignObject.sign==this->sign)
                    {
                        for(int i=0; i<v1.size(); i++)
                        {
                            if(v1[i]<decStr2.v1[i])
                            {
                                if(v1[i+1]!=0)
                                {
                                    v1[i]+=10;
                                    v1[i+1]-=1;
                                }
                                else
                                {
                                    v1[i+2]-=1;
                                    v1[i+1]=9;
                                    v1[i]+=10;
                                }
                                diffrentSignObject.v1.push_back(v1[i]-decStr2.v1[i]);

                            }
                            else
                            {
                                diffrentSignObject.v1.push_back(v1[i]-decStr2.v1[i]);
                            }


                        }


                    }
                    else if(diffrentSignObject.sign==decStr2.sign)
                    {
                        for(int i=0; i<decStr2.v1.size(); i++)
                        {
                            if(v1[i]>decStr2.v1[i])
                            {
                                if(decStr2.v1[i+1]!=0)
                                {
                                    decStr2.v1[i]+=10;
                                    decStr2.v1[i+1]-=1;
                                }
                                else
                                {
                                    decStr2.v1[i+2]-=1;
                                    decStr2.v1[i+1]=9;
                                    decStr2.v1[i]+=10;
                                }
                                diffrentSignObject.v1.push_back(decStr2.v1[i]-v1[i]);
                            }
                            else
                            {
                                diffrentSignObject.v1.push_back(decStr2.v1[i]-v1[i]);
                            }
                        }

                    }



                }
            }
        }
        else
        {
            if(this->sizee()>decStr2.sizee())
            {
                diffrentSignObject.sign=this->sign;
                for(int i=decStr2.sizee(); i<v1.size(); i++)
                {
                    decStr2.v1.push_back(0);

                }
                for(int i=0; i<v1.size(); i++)
                {
                    if(v1[i]<decStr2.v1[i])
                    {
                        if(v1[i+1]!=0)
                        {
                            v1[i]+=10;
                            v1[i+1]-=1;
                        }
                        else
                        {
                            v1[i+2]-=1;
                            v1[i+1]=9;
                            v1[i]+=10;
                        }
                        diffrentSignObject.v1.push_back(v1[i]-decStr2.v1[i]);

                    }
                    else
                    {
                        diffrentSignObject.v1.push_back(v1[i]-decStr2.v1[i]);
                    }
                }


            }
            else if(this->sizee()<decStr2.sizee())
            {
                diffrentSignObject.sign=decStr2.sign;
                for(int i=this->sizee(); i<decStr2.v1.size(); i++)
                {
                    v1.push_back(0);
                }
                for(int i=0; i<decStr2.v1.size(); i++)
                {
                    if(v1[i]>decStr2.v1[i])
                    {
                        if(decStr2.v1[i+1]!=0)
                        {
                            decStr2.v1[i]+=10;
                            decStr2.v1[i+1]-=1;
                        }
                        else
                        {
                            decStr2.v1[i+2]-=1;
                            decStr2.v1[i+1]=9;
                            decStr2.v1[i]+=10;
                        }
                        diffrentSignObject.v1.push_back(decStr2.v1[i]-v1[i]);
                    }
                    else
                    {
                        diffrentSignObject.v1.push_back(decStr2.v1[i]-v1[i]);
                    }
                }
            }


        }
        reverse(diffrentSignObject.v1.begin(),diffrentSignObject.v1.end());

        return diffrentSignObject;
    }
    BigDecimalint SubSameSign(BigDecimalint &decStr2)
    {
        if(this->sign==decStr2.sign&&this->sign==false)
        {
            decStr2.sign=true;
            BigDecimalint SubSameSignResult=addDiffrentSign(decStr2);
            return SubSameSignResult;
        }
        else if(this->sign==decStr2.sign&&this->sign==true)
        {
            decStr2.sign=false;
            BigDecimalint SubSameSignResult=addDiffrentSign(decStr2);
            return SubSameSignResult;
        }
    }
    BigDecimalint SubDiffrentSign(BigDecimalint &decStr2)
    {
            if(this->sign!=decStr2.sign&&decStr2.sign==true)
            {
                decStr2.sign=false;
                BigDecimalint SubDiffrentSignResult=addSameSign(decStr2);
                return SubDiffrentSignResult;
            }
            else if(this->sign!=decStr2.sign&&this->sign==true)
            {
               decStr2.sign=true;
                BigDecimalint SubDiffrentSignResult=addSameSign(decStr2);
                return SubDiffrentSignResult;
            }
    }
    BigDecimalint addSameSign(BigDecimalint  &decStr2)
    {
        vector<int> sumVector;
        int carry =0;
        if(this->sizee()>decStr2.sizee())
        {
            for(int i=decStr2.sizee(); i<v1.size(); i++)
            {
                decStr2.v1.push_back(0);

            }
        }
        else if(this->sizee()<decStr2.sizee())
        {
            for(int i=this->sizee(); i<decStr2.v1.size(); i++)
            {
                v1.push_back(0);
            }
        }
        for(int i=0; i<v1.size(); i++)
        {
            sumVector.push_back(((v1[i]+decStr2.v1[i])%10)+carry);
            if((v1[i]+decStr2.v1[i])>9)
            {
                carry=1;
                continue;
            }
            carry=0;
        }
        if(carry==1)
            sumVector.push_back(1);

        BigDecimalint sumed;
        sumed.sign=this->sign;
        reverse(sumVector.begin(),sumVector.end());
        sumed.v1=sumVector;
        return sumed;
    }
    int sizee()
    {
        return v1.size();
    }
    friend  ostream& operator <<(ostream& out,BigDecimalint &bigdec )
    {
        bool leftzeros=true;
        vector<int>::iterator it;
        int x;
        bool allzeros=true;
        for(int i=0; i<bigdec.sizee(); i++)
        {
            if(bigdec.v1[i]!=0)
            {
                x=i;
                allzeros=false;
                break;

            }

        }
        if(bigdec.sign&&allzeros==false)
            out<<'-';

        if(allzeros)
        {
            out<<0;
        }
        else
        {
            for(int i=x; i<bigdec.sizee(); i++)
            {
                out<<bigdec.v1[i];
            }
        }


        return out;
    }

};

int main()
{
   // Test 1
    BigDecimalint r1("123456789012345678901234567890");
    BigDecimalint r2("113456789011345678901134567890");
    BigDecimalint sum=r1+r2;
    cout<<sum;

    /*//Test 2
    BigDecimalint r1("-1230000000000000001");
    BigDecimalint r2("30000000000000001");
    BigDecimalint sum=r1+r2;
    cout<<sum;*/

    /*//Test 3
    BigDecimalint r1("1230000000000000001");
    BigDecimalint r2("30000000000000001");
    BigDecimalint sum=r1-r2;
    cout<<sum;*/

    return 0;
}
