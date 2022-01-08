#include "Utils.h"

LVector2f Utils::calculateGravity(int pm1, int pm2, LVector2f ppos1, LVector2f ppos2)
{
    int r_squared = ((ppos2.x - ppos1.x) * (ppos2.x - ppos1.x)) + ((ppos2.y - ppos1.y) * (ppos2.y - ppos1.y));

    double numGrav = 5 * (((double)pm1 * (double)pm2) / (double)r_squared);
    if (numGrav > 100.0)
    {
        numGrav = 1.0;
    }
    

    LVector2f dirVec = {(double)(ppos2.x - ppos1.x), (double)(ppos2.y - ppos1.y)};

    double dist = sqrt((dirVec.x * dirVec.x) + (dirVec.y * dirVec.y));

    LVector2f normedVec = {dirVec.x / dist, dirVec.y / dist};

    LVector2f grav = {normedVec.x * numGrav, normedVec.y * numGrav};

    return grav;
}