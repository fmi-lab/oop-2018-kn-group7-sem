// - mydata.in --- 
// - zip -> mydata.zip
// - encrypted -> mydate.in.crypto
// - zipped & encrypted -> mydate.in.zip.crypto
// - encrypted & zipped -> mydate.in.crypto.zip


// if (endsWith(filename, ".in")) {
// 	PlainTextParser(filename)
// } else if (endsWith(filename, ".in.crypto.zip")) {
// 	ZippedAndEncryptedParser(filename);
// }


class AbstractDataParser {
public:
	virtual MyData readData(istream in) = 0;
}

class DataParserWrapper : public AbstractDataParser {
public:
	DataParserWrapper(AbstractDataParser dataParser) {
		this->dataParser = dataParser;
	}

	virtual MyData readData(istream in) {
		dataParser.readData(in);
	}
private:
	AbstractDataParser dataParser;
}


class ZippedDataParser {
	ZippedDataParser(char * filename) {}

	MyData readData() {
		ifstream file(filename);
		readData(unzip(file));
	}
	
	istream unzip(istream in) {
		// ... 
		return decryptedIn;
	}

	virtual MyData readData(istream in) {
		// plain data processing (mydata.in)
	}
}

class EncryptedDataParser : public DataParserWrapper {
	EncryptedDataParser(AbstractDataParser dataParser): DataParserWrapper(dataParser) {}

	istream decrypt(istream in) {
		// ... 
		return decryptedIn;
	}

	virtual MyData readData(istream in) {
		dataParser.readData(decrypt(in));
	}
}

class MyDataParser : public AbstractDataParser {
public:
	virtual MyData readData(istream in) {
		// plain data processing (mydata.in)
	}
}

ZippedDataParser(MyDataParser()).readData(istream);
EncryptedDataParser(MyDataParser()).readData(istream);

EncryptedDataParser(ZippedDataParser(MyDataParser())).readData(istream);
ZippedDataParser(EncryptedDataParser(MyDataParser())).readData(istream);




