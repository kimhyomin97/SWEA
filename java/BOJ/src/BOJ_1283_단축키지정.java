import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

public class BOJ_1283_단축키지정 {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        boolean[] check = new boolean[27];
        for(int i=0; i<n; i++){
            String[] line = br.readLine().split(" ");
            boolean flag = false;
            for(int j=0; j< line.length; j++){
                char temp = line[j].charAt(0);
                int index = 0;
                if(temp >= 'a') index = temp - 'a';
                else index = temp - 'A';
                if(!check[index]){
                    check[index] = true;
                    line[j] = "[" + line[j].charAt(0) + "]" + line[j].substring(1);
                    flag = true;
                    break;
                }
            }

            if(!flag){
                for(int j=0; j<line.length; j++){
                    for(int k=0; k<line[j].length(); k++){
                        char temp = line[j].charAt(k);
                        int index = 0;
                        if(temp >= 'a') index = temp - 'a';
                        else index = temp - 'A';
                        if(!check[index]){
                            check[index] = true;
                            line[j] = line[j].substring(0, k) + "[" + line[j].charAt(k) + "]" + line[j].substring(k+1);
                            flag = true;
                            break;
                        }
                    }
                    if(flag) break;
                }
            }

            for(int j=0; j<line.length; j++){
                System.out.print(line[j]+" ");
            }
            System.out.println();
        }
    }
}
