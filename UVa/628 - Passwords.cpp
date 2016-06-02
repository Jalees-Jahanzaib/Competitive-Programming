/* USER: 308958 (osdajigu) */
/* PROBLEM: 569 (628 - Passwords) */
/* SUBMISSION: 14576386 */
/* SUBMISSION TIME: 2014-11-24 04:07:04 */
/* LANGUAGE: 2 */

import java.util.Scanner;


class Main {
	
	public static void cade(String name, String rule, int pos, String name2){

		if(pos == rule.length()){
			System.out.println(name2);
			return;
		}
		
		if(rule.charAt(pos) == '#'){
			cade(name, rule, pos + 1,name2.concat(name));
		}else{
			for (int i = 0; i < 10; i++) {
				cade(name, rule, pos + 1, name2.concat(i+""));
			}
			}
		}


	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		while(scan.hasNext()){
			System.out.println("--");
			int n = Integer.parseInt(scan.nextLine());
			String[] s = new String[n];
			for (int i = 0; i < n; i++) {
				s[i] = scan.nextLine();
			}
			int p = Integer.parseInt(scan.nextLine());
			String[] r = new String[p];
			for (int i = 0; i < p; i++) {
				r[i] = scan.nextLine();
				
			
			}
			
			for (int i = 0; i < p; i++) {
				for (int j = 0; j < n; j++) {
					cade(s[j], r[i], 0, "");
				}
			}
		}
	}
}
