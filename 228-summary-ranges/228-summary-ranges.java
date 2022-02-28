import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> summaryRanges(int[] nums) {
        ArrayList<String> result = new ArrayList<>();
        if(nums == null || nums.length == 0) return result;
        ArrayList<Integer> continuousRange = new ArrayList<Integer>();
        for(int i = 0; i < nums.length; i++){
            if(continuousRange.isEmpty() || continuousRange.get(continuousRange.size() - 1) + 1 == nums[i]){
                continuousRange.add(nums[i]);
            }else{
                if(continuousRange.size() == 1){
                    result.add(continuousRange.get(0).toString());
                }else{
                    result.add(
                            continuousRange.get(0).toString() +
                                    "->" +
                                    continuousRange.get(continuousRange.size()-1).toString());
                }
                continuousRange.clear();
                continuousRange.add(nums[i]);
            }

        }
        if(continuousRange.size() == 1){
            result.add(continuousRange.get(0).toString());
        }else{
            result.add(
                    continuousRange.get(0).toString() +
                            "->" +
                            continuousRange.get(continuousRange.size()-1).toString());
        }
        return result;
    }
}