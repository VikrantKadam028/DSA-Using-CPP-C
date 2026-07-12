class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        long long ans = 0;

        int n = startTime.length();
        int cntHS = 0;
        string startH = "";

        int cntHE = 0;
        string endH = "";

        int idx = 0;
        int diffH = 0;
        // for hours
        for (int i = 0; i < n; i++) {
            if (startTime[i] == ':') {
                idx = i;
                break;
            }
            if (cntHS < 3) {
                startH += startTime[i];
                cntHS++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (endTime[i] == ':') {
                break;
            }
            if (cntHE < 3) {
                endH += endTime[i];
                cntHE++;
            }
        }
        
        diffH = stoi(endH) - stoi(startH);
        idx += 1; // move past ':'

        int cntSM = 0;
        string startM = "";

        int cntEM = 0;
        string endM = "";

        int idxM = 0;
        int diffM = 0;
        // for minutes
        for (int i = idx; i < n; i++) {
            if (startTime[i] == ':') {
                idxM = i;
                break;
            }
            if (cntSM < 3) {
                startM += startTime[i];
                cntSM++;
            }
        }
        
        for (int i = idx; i < n; i++) {
            if (endTime[i] == ':') {
                break;
            }
            if (cntEM < 3) {
                endM += endTime[i];
                cntEM++;
            }
        }
        
        diffM = stoi(endM) - stoi(startM);
        idxM += 1; // move past ':'

        int cntSS = 0;
        string startS = "";

        int cntES = 0;
        string endS = "";

        int diffS = 0;
        // for seconds
        for (int i = idxM; i < n; i++) {
            if (cntSS < 3) {
                startS += startTime[i];
                cntSS++;
            }
        }
        
        for (int i = idxM; i < n; i++) {
            if (cntES < 3) {
                endS += endTime[i];
                cntES++;
            }
        }
        
        diffS = stoi(endS) - stoi(startS);

        ans = diffH * 3600 + diffM * 60 + diffS;
        return ans;
    }
};