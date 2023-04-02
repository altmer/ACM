
public class OneArmedBandit {

    public double progressiveJackpot(String[] wheels, String jackpotLine, String[] payoffTable) {
        double gain=0;
        for (String s : payoffTable){
            String[] res = s.split("\\s");
            s = res[0];
            double exp=1.0;
            for (int i=0; i<s.length(); ++i){
                int cnt=0;
                if(s.charAt(i)=='-')
                    continue;
                for (int j=0; j<wheels[i].length(); ++j){
                    if(wheels[i].charAt(j)==s.charAt(i)){
                        ++cnt;
                    }
                }
                exp*=(double)cnt/(double)wheels[i].length();
            }
            exp*=Double.parseDouble(res[1]);
            gain+=exp;
        }
        if(gain>1){
            return 0.0;
        }

        double prob=1.0;
        for (int i=0; i<jackpotLine.length(); ++i){
            int cnt=0;
            if(jackpotLine.charAt(i)=='-')
                continue;
            for (int j=0; j<wheels[i].length(); ++j){
                if(wheels[i].charAt(j)==jackpotLine.charAt(i)){
                    ++cnt;
                }
            }
            prob*=(double)cnt/(double)wheels[i].length();
        }

        if(prob<1e-8){
            return -1.0;
        }

        return (1-gain)/prob;
    }
/*
    public static void main(String[] args) {
    }
*/
}
