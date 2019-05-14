class DataProcessingStrategy {
public: 
	void processData() {
		cout << "Start processing the data!" << endl;
		load();
		cout << "Number of records loaded: " << numberOfRecords;
		if (transform()) {
			cout << "Data was transformed succesufully!" << endl;
			save();
			cout << "Data saved" << endl;
		} else {
			cout << "Error transforming the data!!!" << endl;
		}
	}
protected:
	virtual void load() = 0;
	virtual bool transform() = 0;
	virtual void save() = 0;
private:
	int numberOfRecords;
};


class FileDataProcessingStategy : public DataProcessingStrategy {
protected:
	FileDataProcessingStategy(char * inputFile, char * outputFile) {}
	
	virtual void load() {
		ifstream file(inputFile);
		load(file);
		file.close();
	}
	
	virtual void save() {
		ofstream file(outputFile);
		save(file);
		file.close();
	}

	virtual void load(istream) = 0;
	virtual bool transform() = 0;
	virtual void save(ostream) = 0;

private:
	char * inputFile;
	char * outputFile;
}


-- Test - saved in a file, remove all multiple choice questions, replace the file

class RemoveMultipleChoiceQuestions : public FileDataProcessingStategy {
public:
	RemoveMultipleChoiceQuestions() : FileDataProcessingStategy("myfile.test", "myfile.test") {}

protected:
	virtual void load(istream in) {
		// ... 
	};
	virtual bool transform() {
		// foreach questions if multiple choice ... skip
	}
	virtual void save(ostream out) {
		// ... out
	}
}

-- Change question 5 from 1 to 2 points
class FixQuestion5Points : public DataProcessingStrategy {
public:
	RemoveMultipleChoiceQuestions() : FileDataProcessingStategy("myfile.test_results", "myfile.test_results") {}

protected:
	virtual void load(istream in) {
		// ... 
	};
	virtual bool transform() {
		// foreach questions 5 add 1 point
	}
	virtual void save(ostream out) {
		// ... out
	}
}
