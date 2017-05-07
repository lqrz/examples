const a_sync = () => {
	console.log('a');
};

const a_async = async () => {
	await new Promise((resolve, reject) => {	// i can only await funcs that return a promise
		setTimeout(() => {
			console.log('a');
			resolve();
		}, 2000);
	});

	console.log('I got past the timeout');
};

const a_async_promise = () => {
	return new Promise((resolve, reject) => {

		let data = null;

		setTimeout(() => {
			resolve('a');	// resolve is inside the async callback
		}, 2000);

		console.log('I got past the timeout');	// this will still run before the async callback

	});

};

const b = () => {
	console.log('b');
};

const c = () => {
	console.log('c');
};

const main = () => {
	a_async_promise()
	.then((data) => {
		console.log(data);
		b();
		c();
		});
};

const main_await = async () => {
	var data = await a_async();		// i can only await funcs that return a promise
	console.log(data);
	b();
	c();
};

main_await();
