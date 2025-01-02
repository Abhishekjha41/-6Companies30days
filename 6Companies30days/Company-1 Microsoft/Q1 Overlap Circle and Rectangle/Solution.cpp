class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        int xclosest = max(x1, min(xCenter, x2));
        int yclosest = max(y1, min(yCenter, y2));

        int distx = xCenter - xclosest;
        int disty = yCenter - yclosest;

        if (distx * distx + disty * disty <= radius * radius)
            return true;
        return false;
    }
};