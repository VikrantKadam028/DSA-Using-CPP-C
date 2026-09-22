class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        int xi, yi;

        //find the nearest point first
        xi = clamp(xCenter, x1, x2);
        yi = clamp(yCenter,y1, y2);

        // if(x1 > xCenter){
        //     xi = x1;
        // }else if(x2 < xCenter){
        //     xi = x2;
        // }else {
        //     xi = xCenter;
        // }

        // if(y1 > yCenter){
        //     yi = y1;
        // }else if(y2 < yCenter){
        //     yi = y2;
        // }else {
        //     yi = yCenter;
        // }


        //distance between nearest point of rec to circle dist.
        int d = sqrt((xi - xCenter) * (xi - xCenter) + (yi - yCenter) * ( yi - yCenter));

        return d <= radius;
    }
};