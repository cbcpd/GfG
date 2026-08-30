class Solution {
    public ArrayList<Integer> getMarks(int[] l, int[] r, int[] rank) {
        ArrayList<Integer> res = new ArrayList<>();

        for(int x:rank){
            int count = 0;

            for(int i=0;i<l.length;i++){
                int size = r[i] - l[i] + 1;

                if(x <= count + size){
                    int mark = l[i] + (x-count - 1);
                    res.add(mark);
                    break;
                }
                count+= size;
            }
        }
        return res;
    }
}
