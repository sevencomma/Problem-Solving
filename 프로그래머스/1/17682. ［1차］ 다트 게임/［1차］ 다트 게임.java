import java.util.regex.*;

class Solution {
    public int solution(String dartResult) {
        String regex = "([0-9]+)([SDT])([*#]?)";
        
        Pattern p = Pattern.compile(regex);
        Matcher m = p.matcher(dartResult);
        
        int total = 0;
        int[] point = new int[3];
        int i = 0;
        
        while (m.find()) {
            int score = Integer.parseInt(m.group(1));
            String bonus = m.group(2);
            String option = m.group(3);
            
            if (bonus.equals("D")) score *= score;
            if (bonus.equals("T")) score *= (score * score);
        
            if (option.equals("")) 
                point[i] = score;
            else if (option.equals("#"))
                point[i] = -score;
            else {
                point[i] = score * 2;
                if (i > 0)
                    point[i - 1] *= 2;
            }
            i++;
        }
        
        total = point[0] + point[1] + point[2];
        return total;
    }
}