#include <iostream>

using namespace std;

/* Ovoj primer ne se kompajlira zatoa sto gi zamenivme P i R, a pritoa P pretstavuvase vlezen tip i R izlezen.
   Na vakov nacin ne moze da se konvertiraat podatocite, zatoa sto povratniot tip ne e postaven kako prv
   parametar vo definicijata na samiot template i kompajlerot ne gi prepoznava soodvetno. */

template<typename R, typename P>

P implicit_cast(const R& r) {
    return r;
}

int main() {
    int i=1;
    float x=implicit_cast<float>(i);
    int j=implicit_cast<int>(x);
}
