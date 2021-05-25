#ifndef RATIO_H_INCLUDED
#define RATIO_H_INCLUDED

class ratio;
ratio(ratio const &src);
void ratio::normalize();
int ratio::gcf(int a, int b);
int ratio::lcm(int a, int b);
ratio ratio::add(const ratio &other);
ratio ratio::sub(const ratio &other);
ratio ratio::mult(const ratio &other);
ratio ratio::div(const ratio &other);
ostream &operator<<(ostream &os, ratio &r);

#endif // RATIO_H_INCLUDED
