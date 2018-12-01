class Stu(object):
	"""docstring for Stu"""
	def __init__(self, arg):
		self.arg = arg
		self.score = 100
	@property
	def score(self):
		return self._score

	@score.setter
	def score(self, value):
		if not isinstance(value, int):
			raise ValueError('score must be an integer!')
		if value < 0 or value > 100:
			raise ValueError('score must between 0 ~ 100!')
		self._score = value
	def printScore(self):
		print("score:", self.score)

a = Stu(2)

print(dir(a))

a.printScore()
		