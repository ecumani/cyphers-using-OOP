#include<iostream>
#include<string>

#include<stdlib.h>
#include<conio.h>
#include<unordered_map>
using namespace std;
void title(string s)
{
    system("cls");
    cout<<"---------------------------"<<endl;
    cout<<"     "<<s<<endl;
    cout<<"---------------------------"<<endl;

}


class ceaser
{
    int key;
    
    string encrypt;
    string decrypt;
    public:
    void encryptces(string);
    void decryptces(string);
    string getencrypt()const;
    string getdecrypt()const;
    ceaser();
    void setkey(int);
    int getkey()const;

};

ceaser::ceaser()
{
    key=5;
}

void ceaser::encryptces(string x)
{
        char temp;
        string encrypted="";
        int i;
    
    
        for(i = 0; x[i] != '\0'; ++i)
        {
            temp = x[i];
        
            if(temp >= 'a' && temp <= 'z')
            {
                temp = temp + key;
        
                if(temp > 'z')
                {
                    temp = temp - 'z' + 'a' - 1;
                }
        
                encrypted += temp;
            }
        
            else if(temp >= 'A' && temp <= 'Z')
            {
                temp = temp + key;
        
                if(temp > 'Z')
                {
                    temp = temp - 'Z' + 'A' - 1;
                }
        
        
                encrypted +=temp;
            }
        }
    
        encrypt=encrypted;
}

void ceaser::decryptces(string x)
{
        string decrypted="";
        int i;
        char temp;
    
        for(i = 0; x[i] != '\0'; ++i)
        {
            temp=x[i];
        
            if(temp >= 'a' && temp <= 'z')
            {
                temp = temp - key;
        
                if(temp < 'a')
                {
                    temp = temp + 'z' - 'a' + 1;
                }
        
                decrypted += temp;
            }
        
            else if(temp >= 'A' && temp <= 'Z')
            {
                temp = temp - key;
        
                if(temp < 'A')
                {
                    temp = temp + 'Z' - 'A' + 1;
                }
        
                decrypted += temp;
            }
        }
    decrypt=decrypted;
        
}

string ceaser::getencrypt()const
{
    return encrypt;
}

string ceaser::getdecrypt()const
{
    return decrypt;
}

void ceaser::setkey(int x)
{
    key=x;
}

int ceaser::getkey()const
{
    return key;
}


class monoalpha
{
    string alpha;
    string key;
    string encrypted;
    string decrypted;
    unordered_map<char,char> hashMap;
    void hashFn(int);
    public:
    monoalpha();
    string getkey()const;
    void setkey(string);
    void encryptmono(string);
    void decryptmono(string);
    string getencrypt()const;
    string getdecrypt()const;
    
    

};
void monoalpha::hashFn(int op)
{
  string a,b;
  int i;
  hashMap.clear();
  if(op==1)
  {
    a=alpha;
    b=key;
    
    for(i=0; i<a.size(); i++)
    {
        hashMap.insert(make_pair(a[i],b[i]));
    }
  }
  else if(op==-1)
  {
      a=key;
      b=alpha;
      for(i=0; i<a.size(); i++)
    {
        hashMap.insert(make_pair(a[i],b[i]));
    }

  }
}

monoalpha::monoalpha()
{
    alpha="abcdefghijklmnopqrstuvwxyz";
    key="mwertyuiopasdfghjklzxcvbnq";
    
}

string monoalpha::getkey()const
{
    return key;
}

void monoalpha::setkey(string x)
{
    if(x.size()==26)
    {
        key=x;
        cout<<"key changed"<<endl;
    }
    else
    {
        cout<<"enter valid key"<<endl;
        
    }
}

void monoalpha::encryptmono(string x)
{
    hashFn(1);
    string ciphertext;
  for(int i=0; i<x.size(); i++)
  {
    ciphertext.push_back(hashMap[x[i]]);
  }
  
    encrypted=ciphertext;
}

void monoalpha::decryptmono(string x)
{
    hashFn(-1);
    string ciphertext;
  for(int i=0; i<x.size(); i++)
  {
    ciphertext.push_back(hashMap[x[i]]);
  }
  
    decrypted=ciphertext;
}

string monoalpha::getdecrypt()const
{
    return decrypted;
}

string monoalpha::getencrypt()const
{
    return encrypted;
}


class vigenere
{
    string key;
    string genkey;
    string encrypted;
    string decrypted;
    void makegenkey(string);
    public:
    vigenere();
    void setkey(string);
    string getkey()const;
    void encryptvin(string);
    void decryptvin(string);
    string getencrypt()const;
    string getdecrypt()const;
    


};

vigenere::vigenere()
{
    key="deadpool";
}

void vigenere::setkey(string x)
{
    key=x;
}

string vigenere::getkey()const
{
    return key;
}
void vigenere::makegenkey(string str)
{
    int x = str.size();
    string k;
 
    for (int i = 0; ; i++)
    {
        if (x-1 == i)
            i = 0;
        if (k.size() == str.size())
            break;
        k.push_back(key[i]);
    }
    genkey=k;
}

void vigenere::encryptvin(string str)
{
    makegenkey(str);
    string ciptext;
    int i;
    for ( i = 0; i < str.size(); i++)
    {
        
        char x = (str[i] + genkey[i]-64) %26;
 
        
        x += 'a';
 
        ciptext.push_back(x);
    }
    encrypted=ciptext;
}

void vigenere::decryptvin(string str)
{
    string oritext;
    int i;
    makegenkey(str);
    for (i = 0 ; i < str.size(); i++)
    {
        
        char x = (str[i] - genkey[i]+26 ) %26;
 
        
        x += 'a';
        oritext.push_back(x);
    }
    decrypted=oritext;
}

string vigenere::getencrypt()const
{
    return encrypted;
}
string vigenere::getdecrypt()const
{
    return decrypted;
}


int main()
{
   
    int op=1,i;
    string x;
    ceaser ces;
    while(op)
    {
        title("ceaser cypher");
        cout<<"1-encrypt"<<endl;
        cout<<"2-derypt"<<endl;
        cout<<"3-view key"<<endl;
        cout<<"4-Change key"<<endl;
        cout<<"0-next"<<endl;
        cout<<"enter option:";
        cin>>op;
        switch(op)
        {    
            case 1:
            cout<<"enter string to encrypt:";
            cin>>x;
            ces.encryptces(x);
            cout<<ces.getencrypt()<<endl;
            getch();
            break;
            case 2:
            cout<<"enter string to decrypt:";
            cin>>x;
            ces.decryptces(x);
            cout<<ces.getdecrypt()<<endl;
            getch();
            break;
            case 3:
            cout<<"key-"<<ces.getkey()<<endl;
            getch();
            break;
            case 4:
            cout<<"enter new key:";
            cin>>i;
            ces.setkey(i);
            cout<<"key changed"<<endl;
            getch();
            break;
            
            
            
        }


    }
    op=1;
    monoalpha mono;
    while(op)
    {
        title("Monoalphabetic Cipher");
        cout<<"1-encrypt"<<endl;
        cout<<"2-derypt"<<endl;
        cout<<"3-view key"<<endl;
        cout<<"4-Change key"<<endl;
        cout<<"0-next"<<endl;
        cout<<"enter option:";
        cin>>op;
        switch(op)
        {    
            case 1:
            cout<<"enter string to encrypt:";
            cin>>x;
            mono.encryptmono(x);
            cout<<mono.getencrypt()<<endl;
            getch();
            break;
            case 2:
            cout<<"enter string to decrypt:";
            cin>>x;
            mono.decryptmono(x);
            cout<<mono.getdecrypt()<<endl;
            getch();
            break;
            case 3:
            cout<<"key-"<<mono.getkey()<<endl;
            getch();
            break;
            case 4:
            cout<<"enter new key:";
            cin>>x;
            mono.setkey(x);
            getch();
            break;
            
            
            
        }


    }
    op=1;
    vigenere vig;
    while(op)
    {
        title("Vigenere cipher");
        cout<<"1-encrypt"<<endl;
        cout<<"2-derypt"<<endl;
        cout<<"3-view key"<<endl;
        cout<<"4-Change key"<<endl;
        cout<<"0-next"<<endl;
        cout<<"enter option:";
        cin>>op;
        switch(op)
        {    
            case 1:
            cout<<"enter string to encrypt:";
            cin>>x;
            vig.encryptvin(x);
            cout<<vig.getencrypt()<<endl;
            getch();
            break;
            case 2:
            cout<<"enter string to decrypt:";
            cin>>x;
            vig.decryptvin(x);
            cout<<vig.getdecrypt()<<endl;
            getch();
            break;
            case 3:
            cout<<"key-"<<vig.getkey()<<endl;
            getch();
            break;
            case 4:
            cout<<"enter new key:";
            cin>>x;
            vig.setkey(x);
            cout<<"key changed"<<endl;
            getch();
            break;
            
            
            
        }


    }

}




