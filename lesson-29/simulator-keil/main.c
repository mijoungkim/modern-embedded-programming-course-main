#include "shape.h"
#include "qassert.h" /* for Q_ASSERT */

#include <stdlib.h> /* for malloc() and free() */

Q_DEFINE_THIS_FILE /* file name for assertions */

Shape s1; /* static allocation */

int main(void) {
    Shape s2; /* automatic allocation */
    Shape *ps3 = malloc(sizeof(Shape)); /* dynamic allocation */
    //Shape const *ps1 = &s1; /* const pointer to s1 */

    Shape_ctor(&s1, 1, 2);
    Shape_ctor(&s2, 3, 4);
    Shape_ctor(ps3, 5, 6);

    Shape_moveBy(&s1, 7, 8);
    Shape_moveBy(&s2, 9, 10);
    Shape_moveBy(ps3, -1, -2);
    //Shape_moveBy(ps1, -3, -4);

    Q_ASSERT(Shape_distanceFrom(&s1, &s1) == 0U);
    Q_ASSERT(Shape_distanceFrom(&s1, &s2) ==
             Shape_distanceFrom(&s2, &s1));
    Q_ASSERT(Shape_distanceFrom(&s1, &s2) <=
             Shape_distanceFrom(&s1, ps3)
           + Shape_distanceFrom(ps3, &s2));

    free(ps3);

    while (1) {
    }

    //return 0; // unreachable code
}

//............................................................................
void Q_onAssert(char const *module, int loc) {
    /* TBD: damage control */
    (void)module; /* avoid the "unused parameter" compiler warning */
    (void)loc;    /* avoid the "unused parameter" compiler warning */
    while (1) {   /* hang in an endless loop */
    }
}
