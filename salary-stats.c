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

//total stats[mean, variance, range]
private int total[3];

private int results[3];


// white swe stats
private int w_swe[3];

// NB swe stats
private int nb_swe[3];

//Black or African American swe stats
private int aa_swe[3];


//generate mean, variance and range of 
void total_stats(){
	private int min, max = A_salary[0];
	private int average = 0;
	private int varience = 0;
	
	//calc total min, max, and mean
	for(public int i = 0; i < 10; i++){
		average += A_salary[i];
		if(A_salary[i] < min)
			min = A_salary[i];
		if(A_salary[i] > max)
			max = A_salary[i];
	}
	
	for(i = 0; i < 15; i++){
		average += B_salary[i];
		if(B_salary[i] < min)
			min = B_salary[i];
		if(B_salary[i] > max)
			max = B_salary[i];
	}
	
	for(i = 0; i < 15; i++){
		average += C_salary[i];
		if(C_salary[i] < min)
			min = C_salary[i];
		if(C_salary[i] > max)
			max = C_salary[i];
	}
	
	average = average / 40;
	
	//calc varience
	for(i = 0; i < 10; i++){
		varience += (A_salary[i] - average) * (A_salary[i] - average);
	}
	
	for(i = 0; i < 15; i++){
		varience += (B_salary[i] - average) * (B_salary[i] - average);
	}
	
	for(i = 0; i < 15; i++){
		varience += (C_salary[i] - average)* (C_salary[i] - average);
	}
	
	total[0] = average;
	total[1] = varience / 39;
	total[2] = max - min;
}

void eth_stats_swe(int e){
	results[0] = 0;
	results[1] = 0;
	results[2] = 0;
	private int min = 999999999;
	private int max = 0;
	private int average = 0;
	private int varience = 0;
	
	private int amount = 0;
	
	//calc total min, max, and mean
	for(public int i = 0; i < 10; i++){
		if (A_ethnicity[i] == e && A_role[i] == 2){
			amount += 1;
			
			average += A_salary[i];
			if(A_salary[i] < min)
				min = A_salary[i];
			if(A_salary[i] > max)
				max = A_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(B_ethnicity[i] == e && B_role[i] == 2){
			amount += 1;
			
			average += B_salary[i];
			if(B_salary[i] < min)
				min = B_salary[i];
			if(B_salary[i] > max)
				max = B_salary[i];
		}	
	}
	
	for(i = 0; i < 15; i++){
		if(C_ethnicity[i] == e && C_role[i] == 2){
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
		if (A_ethnicity[i] == e && A_role[i] == 2){
			varience += (A_salary[i] - average) * (A_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(B_ethnicity[i] == e && B_role[i] == 2){
			varience += (B_salary[i] - average) * (B_salary[i] - average);
		}
	}
	
	for(i = 0; i < 15; i++){
		if(C_ethnicity[i] == e && C_role[i] == 2){
			varience += (C_salary[i] - average)* (C_salary[i] - average);
		}
	}
	
	results[0] = average;
	results[1] = varience / (amount - 1);
	results[2] = max - min;
}

void gender_stats_swe(int g){
	results[0] = 0;
	results[1] = 0;
	results[2] = 0;
	private int min = 999999999;
	private int max = 0;
	private int average = 0;
	private int varience = 0;
	
	private int amount = 0;
	
	//calc total min, max, and mean
	for(public int i = 0; i < 10; i++){
		if (A_gender[i] == g && A_role[i] == 2){
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
	
	results[0] = average;
	results[1] = varience / (amount - 1);
	results[2] = max - min;

	
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
	
	private int eth = 0;
	eth_stats_swe(eth);
	w_swe[0] = results[0];
	w_swe[1] = results[1];
	w_swe[2] = results[2];
	
	eth = 1;
	eth_stats_swe(eth);
	aa_swe[0] = results[0];
	aa_swe[1] = results[1];
	aa_swe[2] = results[2];
	
	private int g = 2;
	gender_stats_swe(g);
	nb_swe[0] = results[0];
	nb_swe[1] = results[1];
	nb_swe[2] = results[2];
	
	
	smcoutput(total, 2, 3);
	smcoutput(w_swe, 2, 3);
	smcoutput(aa_swe, 2, 3);
	smcoutput(nb_swe, 2, 3);
	

	return 0;
}
