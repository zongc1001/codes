class MyExc(Exception):
	"""docstring for MyExc"""
	def __init__(self, arg):
		super(MyExc, self).__init__()
		self.arg = arg

def main():
	try:
		raise MyExc("fdsa")
	except MyExc as e:
		print(e.arg)
	pass

if __name__ == '__main__':
	main()