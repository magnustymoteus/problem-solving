using System;
public class Accumul 
{
	public static String Accum(string s) 
  {
    string newStr = string.Empty;
     for(int i=0, c=1;i<s.Length;i++, c++) {
       for(int j=0;j<c;j++) {
        newStr+=(j==0)?(Char.ToUpper(s[i])):(Char.ToLower(s[i]));
       }
       newStr+='-';
     }
    return newStr.Remove(newStr.Length-1);
  }
  public static void Main(string[] args) {
    Console.Write("'{0}'",Accum("ZpglnRxqenU"));
  }
}