# Arguments:
# $1: Sketch name

mkdir "$1"

cd $1

touch "$1.ino"
touch "$1.md"
mkdir "media"

echo "void setup() {" >> "$1.ino"
echo -e '\t' >> "$1.ino"
echo "}" >> "$1.ino"
echo "" >> "$1.ino"
echo "void loop() {" >> "$1.ino"
echo -e '\t' >> "$1.ino"
echo "}" >> "$1.ino"