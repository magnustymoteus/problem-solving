public static class Kata
{
  public static string AlphabetPosition(string text)
  {
    string textVar = "";
    for(int i=0;i<text.Length;i++) {
        textVar+=(text[i]>=65&&text[i]<=90) ? (int)text[i]-64+" ":(text[i]>=97 && text[i]<=122)?(int)text[i]-96+" ":"";
    }
    return (textVar.Length>=1)?textVar.Remove(textVar.Length-1):textVar;
  }
}