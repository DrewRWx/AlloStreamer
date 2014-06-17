all:
	cd AlloStreamer-Server; make
	cd AlloStreamer-UnityPlugin; make

pedantic:
	cd AlloStreamer-Server; make pedantic
	cd AlloStreamer-UnityPlugin; make pedantic

logs:
	rm -r AlloStreamer-Server/Logs Logs

clean: logs
	cd AlloStreamer-Server; make clean
	cd AlloStreamer-UnityPlugin; make clean
