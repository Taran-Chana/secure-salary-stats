/*
Salary: 
	rounded to nearest whole number

Role:
	0: Executives
	1: Management
	2: Software Developer 
	3: Project Manager
	4: HR
	5: Accountant
	6: Sales
	7: Secretary

Gender:
	0: Female
	1: Male
	2: Non-Binary
	3: Other

Ethnicity:
	0: White
	1: Black or African American
	2: American Indian or Alaska Native
	3: Hispanic or Latino
	4: AAPI
	5: South Asian
	6: Other
	7: Two or More Races

Experience:
	years of working experience

*/

//company A
private int A_salary[10];
private int<3> A_role[10];
private int<2> A_gender[10];
private int<3> A_ethnicity[10];
private int A_experience[10];

//company B
private int B_salary[15];
private int<3> B_role[15];
private int<2> B_gender[15];
private int<3> B_ethnicity[15];
private int B_experience[15];

//company C
private int C_salary[15];
private int<3> C_role[15];
private int<2> C_gender[15];
private int<3> C_ethnicity[15];
private int C_experience[15];

//total stats[mean, variance, range, number]
private int<64> total[4];

// white swe stats
private int<64> w_swe[4];

// NB swe stats
private int<64> nb_swe[4];

//Black or African American swe stats
private int<64> aa_swe[4];

private int swe[4];


//generate mean, variance and range of 
void total_stats(){
	private int<64> min = A_salary[0];
	private int<64> max = A_salary[0];
	private int<64> average = 0;
	private int<64> varience = 0;
	private int amount = 0;
	
	//calc total min, max, and mean
	for(public int i = 0; i < 10; i++){
		
		amount =  amount + 1;
		average = average + A_salary[i];
		if(A_salary[i] < min)
			min = A_salary[i];
		if(A_salary[i] > max)
			max = A_salary[i];
	}
	
	for(i = 0; i < 15; i++){
		amount =  amount + 1;
		average = average + B_salary[i];
		if(B_salary[i] < min)
			min = B_salary[i];
		if(B_salary[i] > max)
			max = B_salary[i];
	}
	

	for(i = 0; i < 15; i++){
		amount =  amount + 1;
		average = average + C_salary[i];
		if(C_salary[i] < min)
			min = C_salary[i];
		if(C_salary[i] > max)
			max = C_salary[i];
	}
	
	
	average = average / amount;
	
	//calc varience
	for(i = 0; i < 10; i++){
		varience = varience + (A_salary[i] - average) * (A_salary[i] - average);
	}
	
	for(i = 0; i < 15; i++){
		varience = varience + (B_salary[i] - average) * (B_salary[i] - average);
	}
	
	for(i = 0; i < 15; i++){
		varience = varience + (C_salary[i] - average)* (C_salary[i] - average);
	}
	
	total[0] = average;
	total[1] = varience / (amount - 1);
	total[2] = max - min;
	total[3] = amount;
}

void w_stats_swe(){
	private int<3> e = 0; 
	private int min, max;
	private int<1> unset = 0;
	
	private int average = 0;
	private int varience = 0;
	
	private int amount = 0;
	
	//calc total min, max, and mean
	for(public int i = 0; i < 10; i++){
		if (A_ethnicity[i] == e && A_role == 2){
			if(unset == 0){
				min = A_salary[i];
				max = A_salary[i];
				unset = 1;
			}
			
			amount = amount + 1;
			
			average += A_salary[i];
			if(A_salary[i] < min)
				min = A_salary[i];
			if(A_salary[i] > max)
				max = A_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(B_ethnicity[i] == e && B_role[i] == 2){
			if(unset == 0){
				min = B_salary[i];
				max = B_salary[i];
				unset = 1;
			}
			
			amount = amount + 1;
			
			average += B_salary[i];
			if(B_salary[i] < min)
				min = B_salary[i];
			if(B_salary[i] > max)
				max = B_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(C_ethnicity[i] == e && C_role[i] == 2){
			if(unset == 0){
				min = C_salary[i];
				max = C_salary[i];
				unset = 1;
			}
			amount = amount + 1;
			average += C_salary[i];
			if(C_salary[i] < min)
				min = C_salary[i];
			if(C_salary[i] > max)
				max = C_salary[i];
		}
	}
	
	average = average / amount;
	
	//calc varience
	for(i = 0; i < 10; i++){
		if (A_ethnicity[i] == e && A_role[i] == 2){
			varience = varience + (A_salary[i] - average) * (A_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(B_ethnicity[i] == e && B_role[i] == 2){
			varience = varience + (B_salary[i] - average) * (B_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(C_ethnicity[i] == e && C_role[i] == 2){
			varience = varience + (C_salary[i] - average)* (C_salary[i] - average);
		}
	}

	w_swe[0] = average;
	w_swe[1] = varience / (amount - 1);
	w_swe[2] = max - min;
	w_swe[3] = amount;

}

void aa_stats_swe(){
	private int<3> e = 1; 
	private int min, max;
	private int<1> unset = 0;
	
	private int average = 0;
	private int varience = 0;
	
	private int amount = 0;
	
	//calc total min, max, and mean
	for(public int i = 0; i < 10; i++){
		if (A_ethnicity[i] == e && A_role[i] == 2){
			if(unset == 0){
				min = A_salary[i];
				max = A_salary[i];
				unset = 1;
			}
			
			amount = amount + 1;
			
			average += A_salary[i];
			if(A_salary[i] < min)
				min = A_salary[i];
			if(A_salary[i] > max)
				max = A_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(B_ethnicity[i] == e && B_role[i] == 2){
			if(unset == 0){
				min  = B_salary[i];
				max = B_salary[i];
				unset = 1;
			}
			
			amount = amount + 1;
			
			average += B_salary[i];
			if(B_salary[i] < min)
				min = B_salary[i];
			if(B_salary[i] > max)
				max = B_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(C_ethnicity[i] == e && C_role[i] == 2){
			if(unset == 0){
				min = C_salary[i];
				max = C_salary[i];
				unset = 1;
			}
			amount = amount + 1;
			average += C_salary[i];
			if(C_salary[i] < min)
				min = C_salary[i];
			if(C_salary[i] > max)
				max = C_salary[i];
		}
	}
	
	average = average / amount;
	
	//calc varience
	for(i = 0; i < 10; i++){
		if (A_ethnicity[i] == e && A_role[i] == 2){
			varience = varience + (A_salary[i] - average) * (A_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(B_ethnicity[i] == e && B_role[i] == 2){
			varience = varience + (B_salary[i] - average) * (B_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(C_ethnicity[i] == e && C_role[i] == 2){
			varience = varience + (C_salary[i] - average)* (C_salary[i] - average);
		}
	}
	
	
	aa_swe[0] = average;
	aa_swe[1] = varience / (amount - 1);
	aa_swe[2] = max - min;
	aa_swe[3] = amount;

}


void nb_stats_swe(){
	private int<2> g = 2;
	private int min, max;
	private int<1> unset = 0;
	private int average = 0;
	private int varience = 0;
	private int amount = 0;
	
	//calc total min, max, and mean
	for(public int i = 0; i < 10; i++){
		if (A_gender[i] == g && A_role[i] == 2){
			if(unset == 0){
				min = A_salary[i]; 
				max = A_salary[i];
				unset = 1;
			}

			amount = amount + 1;
			
			average += A_salary[i];
			if(A_salary[i] < min)
				min = A_salary[i];
			if(A_salary[i] > max)
				max = A_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(B_gender[i] == g && B_role[i] == 2){
			if(unset == 0){
				min = B_salary[i];
				max = B_salary[i];
				unset = 1;
			}

			amount = amount + 1;
			
			average += B_salary[i];
			if(B_salary[i] < min)
				min = B_salary[i];
			if(B_salary[i] > max)
				max = B_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(C_gender[i] == g && C_role[i] == 2){
			if(unset == 0){
				min = C_salary[i];
				max = C_salary[i];
				unset = 1;
			}

			amount = amount + 1;
			average += C_salary[i];
			if(C_salary[i] < min)
				min = C_salary[i];
			if(C_salary[i] > max)
				max = C_salary[i];
		}
	}
	
	average = average / amount;
	
	//calc varience
	for(i = 0; i < 10; i++){
		if (A_gender[i] == g && A_role[i] == 2){
			varience = varience + (A_salary[i] - average) * (A_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(B_gender[i] == g && B_role[i] == 2){
			varience = varience + (B_salary[i] - average) * (B_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(C_gender[i] == g && C_role[i] == 2){
			varience = varience + (C_salary[i] - average)* (C_salary[i] - average);
		}
	}
	
	nb_swe[0] = average;
	nb_swe[1] = varience / (amount - 1);
	nb_swe[2] = max - min;
	nb_swe[3] = amount;
	
}

void stats_swe(){
	private int min, max;
	private int<1> unset = 0;
	private int average = 0;
	private int varience = 0;
	private int amount = 0;
	
	//calc total min, max, and mean
	for(public int i = 0; i < 10; i++){
		if (A_role[i] == 2){
			if(unset == 0){
				min = A_salary[i];
				max = A_salary[i];
				unset = 1;
			}

			amount = amount + 1;
			
			average += A_salary[i];
			if(A_salary[i] < min)
				min = A_salary[i];
			if(A_salary[i] > max)
				max = A_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(B_role[i] == 2){
			if(unset == 0){
				min = B_salary[i];
				max = B_salary[i];
				unset = 1;
			}

			amount = amount + 1;
			
			average += B_salary[i];
			if(B_salary[i] < min)
				min = B_salary[i];
			if(B_salary[i] > max)
				max = B_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(C_role[i] == 2){
			if(unset == 0){
				min = C_salary[i];
				max = C_salary[i];
				unset = 1;
			}

			amount = amount + 1;
			average += C_salary[i];
			if(C_salary[i] < min)
				min = C_salary[i];
			if(C_salary[i] > max)
				max = C_salary[i];
		}
	}
	
	average = average / amount;
	
	//calc varience
	for(i = 0; i < 10; i++){
		if (A_role[i] == 2){
			varience = varience + (A_salary[i] - average) * (A_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(B_role[i] == 2){
			varience = varience + (B_salary[i] - average) * (B_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(C_role[i] == 2){
			varience = varience + (C_salary[i] - average)* (C_salary[i] - average);
		}
	}

	swe[0] = average;
	swe[1] = varience / (amount - 1);
	swe[2] = max - min;
	swe[3] = amount;
	
}


public int main(){
	//a input
	smcinput(A_salary, 1, 10);
	smcinput(A_role, 1, 10);
	smcinput(A_gender, 1, 10);
	smcinput(A_ethnicity, 1, 10);
	smcinput(A_experience, 1, 10);
	
	//b input
	smcinput(B_salary, 1, 15);
	smcinput(B_role, 1, 15);
	smcinput(B_gender, 1, 15);
	smcinput(B_ethnicity, 1, 15);
	smcinput(B_experience, 1, 15);
	
	
	//c input
	smcinput(C_salary, 1, 15);
	smcinput(C_role, 1, 15);
	smcinput(C_gender, 1, 15);
	smcinput(C_ethnicity, 1, 15);
	smcinput(C_experience, 1, 15);
	
	total_stats();
	
	//private int<3> eth = 0;
	//eth_stats_swe(eth);
	w_stats_swe();
	
	
	//eth = 1;
	//eth_stats_swe(eth);
	aa_stats_swe();
	
	//private int g = 2;
	//gender_stats_swe(g);
	nb_stats_swe();
	
	stats_swe();
	
	
	smcoutput(total, 2, 4);
	smcoutput(w_swe, 2, 4);
	smcoutput(aa_swe, 2, 4);
	smcoutput(nb_swe, 2, 4);
	smcoutput(swe, 2, 4);

	return 0;
}

/*

void eth_stats_swe(int e){
	
	private int<64> min, max;
	private int<1> unset = 0;
	
	private int<64> average = 0;
	private int<64> varience = 0;
	
	private int amount = 0;
	
	//calc total min, max, and mean
	for(public int i = 0; i < 10; i++){
		if (A_ethnicity[i] == e && A_role[i] == 2){
			if(unset == 0){
				min, max = A_salary[i];
				unset = 1;
			}
			
			amount = amount + 1;
			
			average += A_salary[i];
			if(A_salary[i] < min)
				
			if(A_salary[i] > max)
				max = A_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(B_ethnicity[i] == e && B_role[i] == 2){
			if(unset == 0){
				min, max = C_salary[i];
				unset = 1;
			}
			
			amount = amount + 1;
			
			average += B_salary[i];
			if(B_salary[i] < min)
				min = B_salary[i];
			if(B_salary[i] > max)
				max = B_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(C_ethnicity[i] == e && C_role[i] == 2){
			if(unset == 0){
				min, max = C_salary[i];
				unset = 1;
			}
			amount = amount + 1;
			average += C_salary[i];
			if(C_salary[i] < min)
				min = C_salary[i];
			if(C_salary[i] > max)
				max = C_salary[i];
		}
	}
	
	average = average / amount;
	
	//calc varience
	for(i = 0; i < 10; i++){
		if (A_ethnicity[i] == e && A_role[i] == 2){
			varience = varience + (A_salary[i] - average) * (A_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(B_ethnicity[i] == e && B_role[i] == 2){
			varience = varience + (B_salary[i] - average) * (B_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(C_ethnicity[i] == e && C_role[i] == 2){
			varience = varience + (C_salary[i] - average)* (C_salary[i] - average);
		}
	}
	
	if (e == 0){
		w_swe[0] = average;
		w_swe[1] = varience / (amount - 1);
		w_swe[2] = max - min;
		w_swe[3] = amount;
	}
	
	if(e == 1){
		aa_swe[0] = average;
		aa_swe[1] = varience / (amount - 1);
		aa_swe[2] = max - min;
		aa_swe[3] = amount;
	}
}



void gender_stats_swe(private int g){
	
	private int<64> min, max;
	private int<1> unset = 0;
	private int<64> average = 0;
	private int<64> varience = 0;
	private int<64> amount = 0;
	
	//calc total min, max, and mean
	for(public int i = 0; i < 10; i++){
		if (A_gender[i] == g && A_role[i] == 2){
			if(unset == 0){
				min, max = A_salary[i];
				unset = 1;
			}
			
			amount += 1;
			
			average += A_salary[i];
			if(A_salary[i] < min)
				min = A_salary[i];
			if(A_salary[i] > max)
				max = A_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(B_gender[i] == g && B_role[i] == 2){
			if(unset == 0){
				min, max = B_salary[i];
				unset = 1;
			}
			
			amount += 1;
			
			average += B_salary[i];
			if(B_salary[i] < min)
				min = B_salary[i];
			if(B_salary[i] > max)
				max = B_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(C_gender[i] == g && C_role[i] == 2){
			if(unset == 0){
				min, max = C_salary[i];
				unset = 1;
			}
			
			amount += 1;
			average += C_salary[i];
			if(C_salary[i] < min)
				min = C_salary[i];
			if(C_salary[i] > max)
				max = C_salary[i];
		}
	}
	
	average = average / amount;
	
	//calc varience
	for(i = 0; i < 10; i++){
		if (A_gender[i] == g && A_role[i] == 2){
			varience += (A_salary[i] - average) * (A_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(B_gender[i] == g && B_role[i] == 2){
			varience += (B_salary[i] - average) * (B_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(C_gender[i] == g && C_role[i] == 2){
			varience += (C_salary[i] - average)* (C_salary[i] - average);
		}
	}
	
	if (g == 2){
		nb_swe[0] = average;
		nb_swe[1] = varience / (amount - 1);
		nb_swe[2] = max - min;
		nb_swe[3] = amount;
	}
	
}








*/
