import web
import smbus

bus = smbus.SMBus(1)
address = 0x04

urls = (

    '/', 'index'
)

app = web.application(urls, globals())
render = web.template.render('templates')

class index:
    def GET(self):
#        bus.write_byte(address, 1)
#        return 'hello webpy'
#        return render.index('car')
         index = web.template.frender('templates/index.html')
         return index('car')

    def POST(self):
         data = web.input()
         print(data)
         dir = int(data.get('dir'))
         angle = int(data.get('angle'))
         print(dir)
         print(angle)
         #bus.write_byte(address, dir)
         bus.write_byte_data(address, dir, angle)
         index = web.template.frender('templates/index.html')
         return index(data)

if __name__ == '__main__':
    app.run()
