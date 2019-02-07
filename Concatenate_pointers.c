void concatenate_string(char *original, char *add)
{
   while(*original)
      original++;

   while(*add)
   {
      *original = *add;
      add++;
      original++;
   }
   *original = '\0';
}
