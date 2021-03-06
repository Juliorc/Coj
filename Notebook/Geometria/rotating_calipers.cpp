double calipers(vc points){
	//get hull and lower convex hulls
	//hull[size_u] = lower[0] and viceversa
	vc hull;
	int size;
	double res;

	//i is index of smallest point lexicographically
	//j biggest

	int i, j, k = 0;
	while(k < size){
		//hull[i] and hull[j] are a pair
		res = max(res, distance(hull[i],hull[j]));	
		k++;

		if( cross_product(hull[(j+1) % size] - hull[j], hull[(i+1) % size] - hull[i]) < 0){
			i++;		
		}
		else if( cross_product(hull[(j+1) % size] - hull[j] , hull[(i+1) % size] - hull[i]) == 0 ){
			//hull[i] and hull[j+1]
			//hull[i+1] and hull[j]
			//are a pair;
			res = max(res, distance(hull[i], hull[(j+1) % size]));
			res = max(res, distance(hull[(i+1) % size], hull[j]));
			
			i++;
			j++;
			k++;
		}
		else{
			j++;
		}
		i %= size;
		j %= size;
	}
}
