/*
https://www.codewars.com/kata/growth-of-a-population/cpp
In a small town the population is p0 = 1000 at the beginning of a year. The population regularly increases by 2 percent 
per year and moreover 50 new inhabitants per year come to 
live in the town. How many years does the town need to see its population greater or equal to p = 1200 inhabitants?
*/
class Arge
{
  public:
  static int nbYear(int p0, double percent, int aug, int p)
  {
    unsigned int year=0;
    double sum=p0;
    while(sum<p)
    {
      year++;
      sum=(sum + (sum * (percent/100)) + aug);
    }
    return year;
  }
  
};