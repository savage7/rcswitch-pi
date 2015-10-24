all: send

send: NewRemoteTransmitter.o send-intertechno.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

clean:
	$(RM) *.o send-intertechno
