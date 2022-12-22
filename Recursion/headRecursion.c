// User define header file
#include "main.h"

/*@
 * Head Recursion
 */

int headRecursion( int n)
{
    if (n > 0)
    {
        
        headRecursion(n-1);
        printf("%d ", n);
    }

}


/*@
* Tail Recursion
*/
int tailRecursion(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        tailRecursion(n-1);
    }
}
