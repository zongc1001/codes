class Screen(object):
	"""docstring for Screen"""
	def __init__(self, arg):
		super(Screen, self).__init__()
		self.arg = arg
		
	@property
	def width(self):
		return self._width
	
	@width.setter
	def width(self, value):
		self._width = value

a = Screen(1)
print(dir(a))
from enum import Enum

Month = Enum('Month', ('Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'))
for name, member in Month.__members__.items():
	print(name, '=>', member, ',', member.value)