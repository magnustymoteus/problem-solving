using System;

public class Kata
{
  public static string ToWeirdCase(string s)
  {
    string newStr = string.Empty;
    for(int i=0, c=0;i<s.Length;i++,c++) {
      newStr+=(c%2==0)?(char.ToUpper(s[i])):(char.ToLower(s[i])); 
      if(s[i]==' ') c=-1;
    }
    return newStr;
  }
}