function fun(arr) {
	let res = -1;
	if(arr[0] !== 0) {
		res = 0;
	} else {

		arr.foreach((x,i)=>{
			if(i !== arr.length) {
				if(arr[i] + 1 !== arr[i+1]) {
					res = arr[i] + 1;
				}
			}
		})	
	}
	if(res === -1)
	{
		res = arr.length;
	}

	return res;
}

console.log(fun([0,1,2,3]));