# Arguments:
# $1: Sketch name. if empty, ask to user

project_name=$1

if [ -z $project_name ]
then
	echo Project name:
	read project_name
fi

mkdir "${project_name}"

cd "${project_name}"

arduino_file_name="${project_name}.ino"

touch "${arduino_file_name}"
touch "${project_name}.md"
mkdir "media"

echo "void setup() {" >> "${arduino_file_name}"
echo -e '\t' >> "$arduino_file_name"
echo "}" >> "$arduino_file_name"
echo "" >> "$arduino_file_name"
echo "void loop() {" >> "$arduino_file_name"
echo -e '\t' >> "$arduino_file_name"
echo "}" >> "$arduino_file_name"